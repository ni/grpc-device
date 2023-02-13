# noqa: D100
import pathlib
import re
import sys

VAR_RE = r"[A-Za-z_]\w*"
VAR_FULL_RE = "^" + VAR_RE + "$"
UPPER_VAR_RE = "[A-Z_][A-Z0-9_]*"
UPPER_VAR_FULL_RE = "^" + UPPER_VAR_RE + "$"
DEFAULTS = {
    "int32": 0,
    "float32": 0.0,
    "float64": 0.0,
    # "NIComplexSingle": "complex(0.0, 0.0)",
}

SPECIAL_DEFINES = {
    "RfsgCheckWarn": 1,
    "playbackCheckWarn": 1,
}


def _convert(txt, driver_pascal):
    # driver_pascal = re.search(r"RFmxCheckWarn\((RFmx\w+?)_", txt).group(1)
    driver_upper = driver_pascal.upper()

    acronyms = _get_acronyms(txt)

    metadatas = {}
    metadatas[driver_pascal] = _Metadata(driver_pascal)
    functions = metadatas[driver_pascal].functions
    enums = metadatas[driver_pascal].enums

    # update indents
    # txt = re.sub(r"   ", "  ", txt)
    txt = re.sub(r"^((?:   )+) *", lambda m: "  " * (len(m.group(1)) // 3), txt, flags=re.M)
    txt = re.sub(r"^\t+", lambda m: "  " * len(m.group(0)), txt, flags=re.M)

    txt = re.sub(" +$", "", txt, flags=re.M)

    # strip #includes
    txt = re.sub(r"^ *#include\b.*\n", "", txt, flags=re.M)

    # extract and strip #defines
    txt, defines = _extract_and_strip_defines(txt)

    # strip function declarations
    txt = re.sub(r"^void \w+\([^)]*?\);\n", "", txt, flags=re.M)

    # merge line continuations
    # txt = re.sub(r"(?<=[^;{}):\n])\n  +(?=.*;\n)", " ", txt)
    txt = re.sub(r"([,|&=])\n  +", r"\1 ", txt)
    txt = re.sub(r"\(\n  +", r"(", txt)
    txt = re.sub(r"(?<!;)\n  +([|&])", r" \1", txt)
    txt = re.sub(r"\n  += ", r" = ", txt)

    # split into groups
    txt = txt.rsplit("\nError:\n", 1)[0].rstrip("\n")
    if driver_pascal == "RFmxSpecAn" and "    if (menuBrkFlg)\n" in txt:
        txt, prints = txt.split("    if (menuBrkFlg)\n", 1)
        prints = "    if (menuBrkFlg)\n" + prints
    elif (
        driver_pascal == "RFmxWCDMA"
        and "  if( measurementStatus == RFMXWCDMA_VAL_SEM_UPPER_OFFSET_MEASUREMENT_STATUS_PASS)"
        in txt
    ):
        splitter = (
            "  if( measurementStatus == RFMXWCDMA_VAL_SEM_UPPER_OFFSET_MEASUREMENT_STATUS_PASS)"
        )
        txt, prints = txt.split(splitter, 1)
        prints = splitter + prints
    elif "\n  /* Display " in txt:
        txt, prints = re.split(r"\n  /\* Display .*?\*/\s*\n", txt, 1)
    elif "\n  /*Printing " in txt:
        txt, prints = re.split(r"\n  /\*Printing .*?\*/\s*\n", txt, 1)
    else:
        printf_pattern = r'printf\("(?:.*%l?f|(?:\\n)?[-=*]{7}).*"(?:, \w+(?:\[\w+\])?)?\);'
        if re.search(r"\n  " + printf_pattern + r"(?:\n+|$)", txt):
            txt, prints = re.split(r"\n+  " + printf_pattern + r"(?:\n+|$)", txt, 1)
        else:
            txt, prints = re.split(r"\n+  +" + printf_pattern + r"(?:\n+|$)", txt, 1)
    if (
        driver_pascal == "RFmxSpecAn"
        and "  arraySize = (int32)ceil(sampleRate * acquisitionTime) + 10;\n" in txt
    ):
        txt, fetch = txt.split("  arraySize = (int32)ceil(sampleRate * acquisitionTime) + 10;\n", 1)
        fetch = "  arraySize = (int32)ceil(sampleRate * acquisitionTime) + 10;\n" + fetch
    elif (
        driver_pascal == "RFmxWLAN"
        and "/* Initialize" in txt
        and "/*" not in txt.split("/* Initialize", 1)[1]
    ) or (driver_pascal == "RFmxSpecAn" and "TxP_Signal" in txt):
        txt, initiate_line, fetch = re.split(
            r"(\n *RFmxCheckWarn\(" + driver_pascal + r"_Initiate\(.*)", txt
        )
        txt = txt + initiate_line
    else:
        comment_pattern = (
            r"/\* ?(?:Fetch|Retrie?ve|Read) (?:(?:.+ )?(?:[Rr]esults|data|measurements)\.? ?)?\*/"
        )
        if re.search(r"\n+  " + comment_pattern + r"\n+", txt):
            txt, fetch = re.split(r"\n+  " + comment_pattern + r"\n+", txt, 1)
        elif driver_pascal == "RFmxWCDMA":
            txt, initiate_line, fetch = re.split(
                r"(\n *RFmxCheckWarn\(" + driver_pascal + r"_Initiate\(.*)", txt
            )
            txt = txt + initiate_line
        else:
            if not re.search(r"\n+ *" + comment_pattern + r"\n+", txt):
                print(txt)
            txt, fetch = re.split(r"\n+ *" + comment_pattern + r"\n+", txt, 1)
    # txt, initiate, fetch = txt.rpartition(r"_Initiate(")
    # txt, fetch = txt + initiate + fetch.split("\n", 1)[0], fetch.split("\n", 1)[1]

    # trim extra whitespace
    txt = txt.strip("\n")
    txt = re.sub(r"\n\n+", "\n", txt)
    fetch = fetch.strip("\n")
    fetch = re.sub(r"\n\n+", "\n", fetch)
    prints = prints.strip("\n")
    prints = re.sub(r"\n\n+", "\n", prints)

    # re-join important groups
    txt = txt + "\n\n" + fetch
    del fetch

    # strip comments
    txt = _strip_comments(txt)

    # trim trailing whitespace
    txt = re.sub(r"[ \t]+$", "", txt, flags=re.M)
    prints = re.sub(r"[ \t]+$", "", prints, flags=re.M)

    # split merged lines
    merged_re = r'^( +)((?!for)[^"; \n][^";\n]*;) *(\S.*)$'
    while re.search(merged_re, txt, flags=re.M):
        txt = re.sub(merged_re, r"\1\2\n\1\3", txt, flags=re.M)

    txt = txt.replace("int32\t*", "int32 *")
    assert "\t" not in txt

    assert txt.startswith("int main"), txt[:80]
    txt = re.sub(r"^int main.*\n{\n", "", txt)
    assert not txt.startswith("int main")

    inits = re.findall(r"(\w+_Initialize)\(", txt)
    assert len(inits) == 1, inits

    lines = txt.splitlines()
    lines2 = []
    lines3 = []
    todos = []
    variables = {}
    actual_variables = {}
    outer_indent_variables = {}
    declared_variables = set()
    # created_variables = set()
    # created_variables_by_indent = {}
    prev_indent = "  "
    in_for_loop = []
    in_switch_statement = None
    switch_statement_output_vars = set()
    done_with_vars = False
    while lines:
        line = lines.pop(0)
        if not line.strip():
            lines2.append("")
            continue
        if not done_with_vars:
            if re.match("^ *RFmxCheckWarn\(", line):
                # if (
                #     f"({driver_pascal}_Initialize(" in line
                #     or "(niRFSG_init(" in line
                # ):
                done_with_vars = True
                # assert f"({driver_pascal}_Initialize(" in line, line
                rest = line + txt.split(line, 1)[1]
                for v in list(variables):
                    if re.search(r"\b" + v + r"(?:\[\w+\])? *=[^=]", rest):
                        actual_variables[v] = variables.pop(v)
                # for k, v in variables.items():
                #     print({k: v})
                # print()
        if not done_with_vars:
            if line.startswith("  for"):
                lines2.append(line)
                line = lines.pop(0)
                assert line == "  {", line
                lines2.append(line)
                line = lines.pop(0)
                while (
                    re.match(r"^ *\S+ = .*;$", line)
                    or re.match(r"^ *(else )?if ", line)
                    or line.strip() in {"{", "}"}
                ):
                    lines2.append(line)
                    line = lines.pop(0)
                assert lines2[-1] == "  }", (lines2[-1], line)
                lines.insert(0, line)
            else:
                _parse_variable(line, variables)
        else:
            indent, line = re.match("^( *)(.*)", line).groups()
            commented = False
            if len(indent) < len(prev_indent):
                # if prev_indent in created_variables_by_indent:
                #     created_variables -= created_variables_by_indent[prev_indent]
                #     del created_variables_by_indent[prev_indent]
                if outer_indent_variables.get(prev_indent):
                    # sys.stderr.write(f"  Restoring {outer_indent_variables[prev_indent]}\n")
                    variables.update(outer_indent_variables.pop(prev_indent))
            prev_indent = indent
            if line in ("{", "}", "break;", "else", "default:") or re.match(
                r"^((for|while|if|else if|switch)[ (]|case )", line
            ):
                if line.startswith("for"):
                    m = re.match("^for *\( *(\w+) *=", line)
                    assert m, line
                    if m:
                        v = m.group(1)
                        if v in actual_variables:
                            del actual_variables[v]
                        line = re.sub(r"^for *\( *(.*?) *\)$", r"for (int \1)", line)

                        m = re.match(
                            rf"^for \(int {v} *= *0; {v} *< *(\w+); {v}\+\+ ?\)$",
                            line,
                        ) or re.match(
                            rf"^for \(int {v} *= *0; {v} *< *(\w+); \+\+{v} ?\)$",
                            line,
                        )
                        assert m, (line, v)
                        if m:
                            v2 = m.group(1)
                            if v2 in defines:
                                in_for_loop.append((indent, int(defines[v2])))
                            elif v2 in variables or v2 in actual_variables:
                                in_for_loop.append((indent, v2))
                            else:
                                assert False, (
                                    line,
                                    v2,
                                    list(sorted(defines)),
                                    list(sorted(variables), list(sorted(actual_variables))),
                                )
                elif line == "}" and in_for_loop and in_for_loop[-1][0] == indent:
                    in_for_loop.pop()
                elif line.startswith("switch"):
                    in_switch_statement = indent
                elif line == "}" and in_switch_statement == indent:
                    in_switch_statement = None
            elif f"({driver_pascal}_Initialize(" in line:
                line = "auto session = init_session(stub(), PXI_5663E);"
            elif re.search(r"\(RFmx\w+_Initialize\(", line):
                line_driver_pascal = line.split("(", 1)[1].split("RFmx", 1)[1].split("_", 1)[0]
                line_driver_lower = line_driver_pascal.lower()
                resource_name = line.split("_Initialize(", 1)[1].split(",", 1)[0]
                # line = f"auto {line_driver_lower}_session = init_{line_driver_lower}(stub(), {resource_name});"
                lines2.append(
                    f"{indent}auto {line_driver_lower}_stub = create_stub<nirfmx{line_driver_lower}_grpc::NiRFmx{line_driver_pascal}>();"
                )
                line = f"auto session = init_{line_driver_lower}_session({line_driver_lower}_stub, {resource_name});"
            elif line.startswith(tuple(SPECIAL_DEFINES)):
                pass
            elif line.startswith("strcpy"):
                pass
            elif line.startswith(("printf(", "goto ")):
                continue
            elif re.match(r"^(RFmxCheckWarn\()?RFmx\w+_Build\w+String", line):
                line = re.sub(r"^RFmxCheckWarn\((.*)\);$", r"\1;", line)
                line_driver_pascal, line = line.split("_", 1)
                if line_driver_pascal not in metadatas:
                    metadatas[line_driver_pascal] = _Metadata(line_driver_pascal)
                metadata = metadatas[line_driver_pascal]
                fn, args, end = re.match(r"^(\w+)(\(.*\))(;)$", line).groups()
                fn = _to_lower_snakecase(metadata.functions[fn]["name"])  # , acronyms)
                m = re.match(r"^\((.*)\)$", args)
                assert m, f"{fn}{args}"
                args = m.group(1)
                args = re.split(", *", args)
                if args[0] in variables:
                    type, var, value = variables[args[0]]
                    if value is not None:
                        args[0] = value
                out_str = args.pop()
                args.pop()  # max str size
                args = ", ".join(args)
                response_var = fn.replace("build_", "", 1) + "_response"
                client = (
                    "client"
                    if line_driver_pascal == driver_pascal
                    else line_driver_pascal[4:].lower() + "_client"
                )
                stub = (
                    "stub()"
                    if line_driver_pascal == driver_pascal
                    else line_driver_pascal[4:].lower() + "_stub"
                )
                line = (
                    f"auto {response_var} = {client}::{fn}({stub}, {args});\n"
                    + f"{indent}EXPECT_SUCCESS(session, {response_var});"
                )
                if indent != "  " and "[" not in out_str:
                    outer_indent_variables.setdefault(indent, {})[out_str] = variables[out_str]
                else:
                    pass  # sys.stderr.write(f"Forever changing {out_str} ({indent})\n")
                variables[out_str] = ("char*", out_str, f"{response_var}.selector_string_out()")
                # sys.stderr.write(f"  {out_str} => {variables[out_str][2]}\n")
            elif line == "actualArraySize = 0;" or re.match(
                r"^RFmxCheckWarn\(\w*(Fetch[A-Z]|SpectrumRead\b)", line
            ):
                lines.insert(0, line)
                fetch_lines, fetch_checks = _fetch_fn(
                    indent,
                    lines,
                    lines2,
                    driver_pascal,
                    functions,
                    variables,
                    actual_variables,
                    declared_variables,
                    defines,
                    enums,
                    acronyms,
                    todos,
                )
                lines2 += [indent + l for l in fetch_lines]
                lines3 += fetch_checks
                continue
            elif line.startswith("RFmxCheckWarn"):
                line = line.replace(f"RFmxCheckWarn(", "", 1)
                line_driver_pascal, line = line.split("_", 1)
                if line_driver_pascal not in metadatas:
                    metadatas[line_driver_pascal] = _Metadata(line_driver_pascal)
                metadata = metadatas[line_driver_pascal]
                m = re.match(r"^(\w+)(\(.*\))(\);)$", line)
                assert m, line
                fn, args, end = m.groups()
                if re.search("Set([A-Z]|gNodeB)", fn):
                    attr = fn.replace("Set", "", 1)
                    # attr_metadata = metadata.enum_attrs.get(attr)
                    # attr = _to_lower_snakecase(attr, acronyms)
                    # attr_metadata = metadata.attrs.get(attr.upper())
                    attr_metadata = metadata.attrs_no_unders[attr.upper()]
                    attr = attr_metadata["name"]
                    fn, args, commented = _set_attr(
                        attr, args, variables, driver_upper, attr_metadata, metadata.enums, acronyms
                    )
                elif re.search("Get([A-Z]|gNodeB)", fn):
                    attr = fn.replace("Get", "", 1)
                    # attr_metadata = metadata.enum_attrs.get(attr)
                    # attr = _to_lower_snakecase(attr, acronyms)
                    # attr_metadata = metadata.attrs.get(attr.upper())
                    attr_metadata = metadata.attrs_no_unders[attr.upper()]
                    attr = attr_metadata["name"]
                    fn, args, type, output_to = _get_attr(
                        attr, args, variables, driver_upper, attr_metadata, metadata.enums
                    )
                    # if f"attr_{type}" not in created_variables:
                    #     created_variables.add(f"attr_{type}")
                    #     created_variables_by_indent.setdefault(indent, set())
                    #     created_variables_by_indent[indent].add(f"attr_{type}")
                    declared_output_to = output_to
                    if indent == "  ":
                        for l in lines2:
                            if output_to in l and re.search(r"\b" + output_to + r"\b", l):
                                break
                        else:
                            declared_variables.add(output_to)
                            declared_output_to = f"{type} {output_to}"
                    new_line = (
                        f"{declared_output_to} = GET_ATTR_{ATTR_TYPE_MAP[type].upper()}"
                        + args
                        + ";"
                    )
                    lines2.append(indent + new_line)
                    assert type in DEFAULTS, (type, line)
                    assert "NIComplex" not in type, line
                    if in_for_loop:
                        assert len(in_for_loop) <= 2, (line, in_for_loop)
                        expected_end = "[i]" if len(in_for_loop) == 1 else "[i][j]"
                        assert output_to.endswith(expected_end), (line, output_to, in_for_loop)
                        add_checks = True
                        if in_switch_statement:
                            assert all(isinstance(loop[1], int) for loop in in_for_loop), (
                                line,
                                in_for_loop,
                            )
                            if len(in_for_loop) == 1:
                                if (output_to[:-3] + "[0]") in switch_statement_output_vars:
                                    add_checks = False
                                    for i in range(in_for_loop[-1][1]):
                                        assert (
                                            f"{output_to[:-3]}[{i}]" in switch_statement_output_vars
                                        ), (
                                            output_to,
                                            in_for_loop[-1][1],
                                            switch_statement_output_vars,
                                        )
                                    assert (
                                        f"{output_to[:-3]}[{in_for_loop[-1][i]}]"
                                        not in switch_statement_output_vars
                                    ), (output_to, in_for_loop[-1][1], switch_statement_output_vars)
                                else:
                                    for i in range(in_for_loop[-1][1]):
                                        switch_statement_output_vars.add(f"{output_to[:-3]}[{i}]")
                            else:
                                if (output_to[:-6] + "[0][0]") in switch_statement_output_vars:
                                    add_checks = False
                                    for i in range(in_for_loop[0][1]):
                                        for j in range(in_for_loop[1][1]):
                                            assert (
                                                f"{output_to[:-6]}[{i}][{j}]"
                                                in switch_statement_output_vars
                                            ), (
                                                output_to,
                                                in_for_loop,
                                                switch_statement_output_vars,
                                            )
                                        assert (
                                            f"{output_to[:-6]}[{i}][{in_for_loop[1][i]}]"
                                            not in switch_statement_output_vars
                                        ), (output_to, in_for_loop, switch_statement_output_vars)
                                    assert (
                                        f"{output_to[:-6]}[{in_for_loop[0][i]}][0]"
                                        not in switch_statement_output_vars
                                    ), (output_to, in_for_loop, switch_statement_output_vars)
                                else:
                                    for i in range(in_for_loop[0][1]):
                                        for j in range(in_for_loop[1][1]):
                                            switch_statement_output_vars.add(
                                                f"{output_to[:-6]}[{i}][{j}]"
                                            )
                        if add_checks:
                            if isinstance(in_for_loop[-1][1], int):
                                assert isinstance(in_for_loop[0][1], int), (line, in_for_loop)
                                for i in range(in_for_loop[0][1]):
                                    if len(in_for_loop) == 1:
                                        check = (
                                            f"  EXPECT_EQ({DEFAULTS[type]}, {output_to[:-3]}[{i}]);"
                                        )
                                        assert check not in lines3, check
                                        lines3.append(check)
                                    else:
                                        for j in range(in_for_loop[1][1]):
                                            check = f"  EXPECT_EQ({DEFAULTS[type]}, {output_to[:-6]}[{i}][{j}]);"
                                            assert check not in lines3, check
                                            lines3.append(check)
                            elif len(in_for_loop) == 1:
                                lines3 += [
                                    f"  for (int i = 0; i < {in_for_loop[0][1]}; i++)",
                                    "  {",
                                    f"    EXPECT_EQ({DEFAULTS[type]}, {output_to});",
                                    "  }",
                                ]
                            else:
                                lines3 += [
                                    f"  for (int i = 0; i < {in_for_loop[0][1]}; i++)",
                                    "  {",
                                    f"    for (int j = 0; j < {in_for_loop[1][1]}; j++)",
                                    "    {",
                                    f"      EXPECT_EQ({DEFAULTS[type]}, {output_to});",
                                    "    }",
                                    "  }",
                                ]
                    else:
                        add_check = True
                        if in_switch_statement:
                            if output_to in switch_statement_output_vars:
                                add_check = False
                                assert output_to in switch_statement_output_vars, (
                                    output_to,
                                    switch_statement_output_vars,
                                )
                            else:
                                switch_statement_output_vars.add(output_to)
                        if add_check:
                            check = f"  EXPECT_EQ({DEFAULTS[type]}, {output_to});"
                            assert check not in lines3, check
                            lines3.append(check)
                    continue
                else:
                    assert fn in metadata.functions, (
                        fn,
                        line,
                        line_driver_pascal,
                        list(sorted(metadatas[line_driver_pascal].functions)),
                    )
                    fn_metadata = metadata.functions[fn]
                    fn = _to_lower_snakecase(fn_metadata["name"])  # , acronyms)
                    # # TODO: bad fn name
                    # fn = fn.replace("cfg_gnodeb", "cfgg_node_b")
                    fn, args = _call_fn(
                        fn,
                        args,
                        fn_metadata,
                        variables,
                        actual_variables,
                        metadata.enums,
                        acronyms,
                        todos,
                    )
                client = (
                    "client"
                    if line_driver_pascal == driver_pascal
                    else line_driver_pascal[4:].lower() + "_client"
                )
                stub = (
                    "stub()"
                    if line_driver_pascal == driver_pascal
                    else line_driver_pascal[4:].lower() + "_stub"
                )
                line = (
                    f"EXPECT_SUCCESS(session, {client}::"
                    + fn
                    + args.replace("(stub(),", f"({stub},")
                    + end
                )
                if commented:
                    line = "// TODO: " + line
            elif re.match(r"^\S+ \+?= .*;$", line):
                pass
            elif line.startswith(("displayMarkerData(", "displayMarkerMenu(")):
                pass
            else:
                assert False, line
            lines2.append(indent + line)

    lines2 = [f"  // TODO: {x}" for x in todos] + lines2
    txt = "\n".join(lines2)
    if lines3:
        txt += "\n\n" + "\n".join(lines3)

    for v in re.findall(driver_upper + r"_VAL_\w+", txt):
        # TODO: lots of magic renames shoved into this re.sub()
        if not v.endswith("_STR"):
            # txt = txt.replace(v, v.replace(f"{driver_upper}_VAL_", f"NI{driver_upper}_INT32_"))
            txt = re.sub(
                r"\b" + driver_upper + r"_VAL_(\w+)\b",
                lambda m: m.group(0)
                if m.group(1).endswith("_STR")
                else (
                    f"NI{driver_upper}_INT32_"
                    + re.sub(
                        r"_(\d)GHZ",
                        r"_\1_GHZ",
                        re.sub(r"_TM3_1A", "_TM3_1_A", re.sub(r"_TM2A", "_TM2_A", m.group(1))),
                    )
                ).replace("SSB_PATTERN_CASE_", "SSB_PATTERN_"),
                txt,
            )

    variables = dict(**actual_variables, **variables)
    for v in declared_variables:
        del variables[v]
    sections = txt.split("\n\n")
    for i in range(len(sections)):
        vars = ""
        for v in list(variables):
            if re.search(r"\b(?<!\.)" + v + r"\b", sections[i]):
                type, var, value = variables.pop(v)
                if var.count("[") == 1 and type != "char":
                    if type == "int32":
                        type = "int"
                    if value is None:
                        size = var.rstrip("]").split("[", 1)[1]
                        vars += f"  std::vector<{type}> {v}({size});\n"
                    elif value in ("{ 0 }", "{ 0.0 }"):
                        size = var.rstrip("]").split("[", 1)[1]
                        vars += f"  std::vector<{type}> {v}({size}, {value[1:-2].strip()});\n"
                    else:
                        assert value.startswith("{"), (v, type, var, value)
                        vars += f"  std::vector<{type}> {v} {value};\n"
                else:
                    if value is None:
                        vars += f"  {type} {var};\n"
                    else:
                        vars += f"  {type} {var} = {value};\n"
        sections[i] = vars + sections[i]

        defs = ""
        for d in list(defines):
            if re.search(r"\b" + d + r"\b", sections[i]):
                defs += f"  const auto {d} = {defines.pop(d)};\n"
        sections[i] = defs + sections[i]
    txt = "\n\n".join(sections)

    return txt


class _Metadata:  # noqa: D101
    def __init__(self, driver_pascal):
        driver_lower = driver_pascal.lower()

        this_script = pathlib.Path(__file__)
        metadata_dir = this_script.parent / f"source/codegen/metadata"

        sys.path.insert(0, str(metadata_dir))
        vars = {}
        exec(f"from ni{driver_lower}.functions import functions", vars)
        exec(f"from ni{driver_lower}.enums import enums", vars)
        exec(f"from ni{driver_lower}.attributes import attributes", vars)
        sys.path.pop(0)

        self.functions = {
            v.get("cname", k).replace(f"{driver_pascal}_", "", 1): dict(v, **{"name": k})
            for k, v in vars["functions"].items()
        }
        self.enums = vars["enums"]
        attrs = vars["attributes"]

        self.enum_attrs = {a["enum"]: a for a in attrs.values() if "enum" in a}
        self.attrs = {a["name"]: a for a in attrs.values()}
        self.attrs_no_unders = {a["name"].replace("_", ""): a for a in attrs.values()}


def _strip_comments(txt):
    txt = re.sub(r"^ *//.*\n", "", txt, flags=re.M)
    txt = re.sub(r"//.*", "", txt)
    txt = re.sub(r"^ */\*.*?\*/\n", "", txt, flags=re.M | re.S)
    txt = re.sub(r"/\*.*?\*/", "", txt)
    return txt


def _extract_and_strip_defines(txt):
    txt2 = _strip_comments(txt)
    txt2 = re.sub(r"[ \t]+$", "", txt2, flags=re.M)  # trim trailing whitespace

    defines_re = r"^ *#define +(\w+)\b\s*([^\s\\]|\S.*?[^\\])\n"
    defines = dict(re.findall(defines_re, txt2, flags=re.M | re.S))
    [defines.pop(v) for v in SPECIAL_DEFINES if v in defines]
    if any("\\\n" in v and v not in SPECIAL_DEFINES for v in defines.values()):
        raise RuntimeError(f"Multi-line #defines not supported\n{defines}")
    if any(not v.isdigit() and not re.match(r'^"[^"]*"$', v) for v in defines.values()):
        raise RuntimeError(
            f'Only literals (e.g. 0.0 or "xyz") are supported in #defines\n{defines}'
        )
    txt = re.sub(defines_re, "", txt, flags=re.M | re.S)
    return txt, defines


def _get_acronyms(txt):
    do_prints = False

    txt = _strip_comments(txt)
    acronyms = set(re.findall(r"(?:\b|[a-z])([A-Z][A-Z0-9]+)(?:[A-Z][a-z]|\b)", txt))
    if do_prints:
        print(acronyms)
    acronyms_decreasing_len = list(reversed(sorted(acronyms, key=(lambda a: (len(a), a)))))
    for i in range(len(acronyms_decreasing_len)):
        a = acronyms_decreasing_len[i]
        remaining_acronyms_tuple = tuple(acronyms_decreasing_len[i + 1 :])
        if a.startswith(remaining_acronyms_tuple):
            if do_prints:
                print("!")
            for b in remaining_acronyms_tuple:
                if len(a) - len(b) >= 2 and a.startswith(b):
                    if do_prints:
                        print("+", a[len(b) :])
                    acronyms.add(a[len(b) :])
                    acronyms_decreasing_len = list(
                        reversed(sorted(acronyms, key=(lambda a: (len(a), a))))
                    )
                    break
        elif a.endswith(remaining_acronyms_tuple):
            if do_prints:
                print("!!")
            for b in remaining_acronyms_tuple:
                if len(a) - len(b) >= 2 and a.endswith(b):
                    if do_prints:
                        print("+", a[: -len(b)])
                    acronyms.add(a[: -len(b)])
                    acronyms_decreasing_len = list(
                        reversed(sorted(acronyms, key=(lambda a: (len(a), a))))
                    )
                    break
    i = 0
    while i < len(acronyms_decreasing_len):
        a = acronyms_decreasing_len[i]
        remaining_acronyms_tuple = tuple(acronyms_decreasing_len[i + 1 :])
        if a.startswith(remaining_acronyms_tuple) or a.endswith(remaining_acronyms_tuple):
            if do_prints:
                print("-", acronyms_decreasing_len[i])
            del acronyms_decreasing_len[i]
        else:
            i += 1
    acronyms = set(acronyms_decreasing_len)
    if do_prints:
        print(acronyms)
        sys.exit()
    return acronyms


# def _parse_variable(line, variables):
#    line = line.strip()
#    line = re.sub(";$", "", line)
#    if "=" in line:
#        m = re.match(r"^(?:const )?(\w+ *?\*?) *\b(" + VAR_RE + r"\S*) = (.*)$", line)
#        assert m, line
#        type, var, value = m.groups()
#        type = re.sub(r" +\*", "*", type)
#        name = var.split("[", 1)[0]
#        if type.startswith("NIComplexSingle"):
#            type = type.replace("NIComplexSingle", "nidevice_grpc::NIComplexNumberF32", 1)
#
#        if "[" not in var:
#            while re.match(r'^[^",]+,', value):
#                value, rest = value.split(",", 1)
#                rest = rest.lstrip()
#                variables[name] = (type, var, value)
#
#                m = re.match(r"^(\*?) *\b(" + VAR_RE + r"\S*) = (.*)$", rest)
#                assert m, (line, rest)
#                type_addendum, var, value = m.groups()
#                type = (type.rstrip("*") + type_addendum).rstrip()
#                assert "[" not in var, (line, var)
#                name = var
#
#        variables[name] = (type, var, value)
#    else:
#        m = re.match(r"(\w+ *?\*?) *\b(" + VAR_RE + r"\S*)", line)
#        assert m, line
#        type, var = m.groups()
#        type = re.sub(r" +\*", "*", type)
#        value = None
#
#        name = var.split("[", 1)[0]
#        if type.startswith("NIComplexSingle"):
#            type = type.replace("NIComplexSingle", "nidevice_grpc::NIComplexNumberF32", 1)
#        variables[name] = (type, var, value)


def _parse_variable(line, variables):
    line = line.strip()
    line = re.sub(";$", "", line)
    if "," in line and '"' not in line:
        # print("{" in line, line.count(","), len(re.findall(r", [a-zA-Z_]", line)))
        if (
            "[" not in line and "{" not in line
        ):  # or (line.count(",") == len(re.findall(r", [a-zA-Z_]", line))):
            m = re.match(r"((?: *\w+\b)+)( *\** *\w+(?:\[[^]]+\])?(?: ?= ?|,|$).*)$", line)
            assert m, line
            type, line = m.groups()
            for part in line.split(","):
                _parse_variable(type + " " + part.strip(), variables)
            return

    if "=" in line:
        m = re.match(r"^(?:const )?(\w+ *?\**) *\b(" + VAR_RE + r"\S*) ?= ?(.*)$", line)
        assert m, line
        type, var, value = m.groups()
        type = re.sub(r" +\*", "*", type)
        name = var.split("[", 1)[0]
        if type.startswith("NIComplexSingle"):
            type = type.replace("NIComplexSingle", "nidevice_grpc::NIComplexNumberF32", 1)

        variables[name] = (type, var, value)
    else:
        m = re.match(r"(\w+ *?\**) *\b(" + VAR_RE + r"\S*)", line)
        assert m, line
        type, var = m.groups()
        type = re.sub(r" +\*", "*", type)
        value = None

        name = var.split("[", 1)[0]
        if type.startswith("NIComplexSingle"):
            type = type.replace("NIComplexSingle", "nidevice_grpc::NIComplexNumberF32", 1)
        variables[name] = (type, var, value)


def _to_lower_snakecase(txt, acronyms=set()):
    if acronyms:
        txt = txt.replace("ModAcc", "Modacc").replace("gNodeB", "Gnodeb")
        # for a in acronyms:
        #    if a in txt:
        #        txt = re.sub(r"^" + a + "(?=[A-Z]|\b)", a[0] + a[1:].lower(), txt)
        #        txt = re.sub(r"(?<=[a-z])" + a + "(?=[A-Z]|\b)", a[0] + a[1:].lower(), txt)
        #        txt = re.sub(r"(?<=[A-Z]{2})" + a + "(?=[A-Z]|\b)", a[0] + a[1:].lower(), txt)
        acronyms_re = "|".join(acronyms)
        # txt = re.sub(r"^(" + acronyms_re + r")", lambda m: m.group(1)[0] + m.group(1)[1:].lower(), txt)
        # txt = re.sub(r"(" + acronyms_re + r")", lambda m: m.group(1)[0] + m.group(1)[1:].lower(), txt)
        txt = re.sub(r"(" + acronyms_re + r")", lambda m: "_" + m.group(1).lower(), txt)
    # else:
    if 1:
        # txt = re.sub(r"^([A-Z]{2,})(?=[A-Z])", lambda m: "_" + m.group(1).lower(), txt)
        # txt = re.sub(r"^([A-Z][a-z]+)", lambda m: "_" + m.group(1).lower(), txt)
        txt = re.sub(
            r"([A-Z][A-Z][A-Z0-9]+|[A-Z]+)(?=[A-Z]|$)", lambda m: "_" + m.group(1).lower(), txt
        )
    txt = re.sub(r"([A-Z][a-z]+)", lambda m: "_" + m.group(1).lower(), txt)
    if not acronyms:
        # TODO: bad function names?
        txt = re.sub(r"(?<=\d)qam_", "q_am_", txt)
    return txt.lstrip("_")


ATTR_TYPE_MAP = {
    "char*": "string",
    "int32": "i32",
    "float": "f32",
    "float64": "f64",
}


def _set_attr(attr, args, variables, driver_upper, metadata, enums, acronyms):
    m = re.match(r"^\((.*)\)$", args)
    assert m, (attr, args)
    args = m.group(1)
    args = re.split(", *", args)
    assert re.match(VAR_FULL_RE, args[0]), (attr, args)
    assert len(args) == 3, (attr, args)
    if metadata is None:
        sys.stderr.write(f"  No metadata for {attr.upper()}\n")
    args[0] = "stub(), session"
    if args[1] in variables:
        type, var, value = variables[args[1]]
        if value is not None:
            args[1] = value
    if args[2] in variables:
        type, var, value = variables[args[2]]
        assert type in ATTR_TYPE_MAP, (attr, args, variables[args[2]])
        if value is not None:
            args[2] = value
            if type == "char*":
                if args[2] == '""':
                    args[2] = "std::string()"
                else:
                    args[2] = f"std::string({args[2]})"
        fn = f"set_attribute_{ATTR_TYPE_MAP[type]}"
    else:
        type = metadata["type"] if metadata is not None else "int32"
        assert type in ATTR_TYPE_MAP, (attr, args, variables[args[2]])
        fn = f"set_attribute_{ATTR_TYPE_MAP[type]}"
    if "enum" in (metadata or {}):
        enum_values = enums[metadata["enum"]]["values"]
        enum_value_prefix = enums[metadata["enum"]].get(
            "enum-value-prefix", _to_lower_snakecase(metadata["enum"]).upper()
        )
        if re.match(UPPER_VAR_FULL_RE, args[2]):
            enum_names = tuple(v["name"] for v in enum_values)
            # TODO: bad const name?
            args[2] = re.sub(r"_GNODEB_TYPE_(\d+)([A-Z]+)", r"_G_NODE_B_\1_\2", args[2])
            if args[2].endswith(enum_names):
                num_matching = 0
                for n in enum_names:
                    if args[2].endswith(n):
                        assert metadata["type"] == "int32", (attr, args)
                        args[2] = f"NI{driver_upper}_INT32_{enum_value_prefix}_{n}"
                        num_matching += 1
                assert num_matching == 1, (fn, args, num_matching, enum_names)
            elif re.sub(r"_STR", "", args[2]).endswith(enum_names):
                num_matching = 0
                for n in enum_names:
                    if re.sub(r"_STR", "", args[2]).endswith(n):
                        assert metadata["type"] == "int32", (attr, args)
                        args[2] = f"NI{driver_upper}_STRING_{enum_value_prefix}_{n}"
                        num_matching += 1
                assert num_matching == 1, (fn, args, num_matching, enum_names)
        args.insert(2, f"NI{driver_upper}_ATTRIBUTE_{metadata['name']}")
    else:
        args.insert(2, f"NI{driver_upper}_ATTRIBUTE_{attr.upper()}")
    return fn, f"(" + ", ".join(args) + ")", metadata is None


def _get_attr(attr, args, variables, driver_upper, metadata, enums):
    m = re.match(r"^\((.*)\)$", args)
    assert m, (attr, args)
    args = m.group(1)
    args = re.split(", *", args)
    assert re.match(VAR_FULL_RE, args[0]), (attr, args)
    assert len(args) == 3, (attr, args)
    assert args[-1].startswith("&"), (attr, args)
    output_to = args.pop()[1:]
    # args[0] = "stub(), session"
    args[0] = "session"
    if args[1] in variables:
        type, var, value = variables[args[1]]
        if value is not None:
            args[1] = value
    fn = "get_attribute_i32"  # default to i32
    type = "int32"
    assert metadata, (attr, args)
    if metadata:
        type = metadata["type"]
        assert type in ATTR_TYPE_MAP, (attr, args, metadata)
        fn = f"get_attribute_{ATTR_TYPE_MAP[type]}"
        args.insert(2, f"NI{driver_upper}_ATTRIBUTE_{metadata['name']}")
    else:
        args.insert(2, f"NI{driver_upper}_ATTRIBUTE_{attr.upper()}")
    return fn, f"(" + ", ".join(args) + ")", type, output_to


def _call_fn(fn, args, metadata, variables, actual_variables, enums, acronyms, todos):
    if isinstance(args, str):
        m = re.match(r"^\((.*)\)$", args)
        assert m, f"{fn}{args}"
        args = m.group(1)
        args = re.split(", *", args)
    assert re.match(VAR_FULL_RE, args[0]), (fn, args)
    params = list(metadata["parameters"])
    size_args = set()
    if "_fetch_" in fn or fn.startswith("fetch_") or fn == "spectrum_read":
        assert len(params) >= len(args), (fn, args, metadata)
    else:
        assert len(params) == len(args), (fn, args, metadata)
        for p in params:
            if "size" in p:
                if p["size"]["mechanism"] == "len":
                    size_args.add(p["size"]["value"])
                else:
                    assert False, (f"Need to add support for mechanism", fn, p)
    if size_args:
        size_arg_indexes = [i for i, p in enumerate(params) if p["name"] in size_args]
        for i in reversed(size_arg_indexes):
            del args[i]
            del params[i]

    for i in reversed(range(len(args))):
        if params[i]["direction"] == "out":
            todos.append(
                f"Conversion process ignored {fn}_response.{params[i].get('grpc_name', _to_lower_snakecase(params[i]['name']))}"
            )
            sys.stderr.write(
                f"  Ignoring {fn}_response.{params[i].get('grpc_name', _to_lower_snakecase(params[i]['name']))}\n"
            )
            del args[i]
            del params[i]
    args[0] = "stub(), session"
    for i in range(1, len(args)):
        param = params[i]
        # print("", args[i])
        assert param["direction"] == "in", (fn, args)
        for v in variables:
            # print("  ", v)
            type, var, value = variables[v]
            if v in args[i] and v == var and re.search(r"\b" + v + r"\b", args[i]):
                if value is not None:
                    args[i] = re.sub(r"\b" + v + r"\b", value, args[i])
                # print("    ", args[i])
        do_prints = 0 and fn == "cfg_frequency_reference" and i == 2
        if do_prints:
            print(fn, args[i], param)
        if "enum" in param:  # and re.match(UPPER_VAR_FULL_RE, args[i]):
            enum_names = tuple(v["name"] for v in enums[param["enum"]]["values"])
            enum_value_prefix = enums[param["enum"]].get(
                "enum-value-prefix", _to_lower_snakecase(param["enum"]).upper()
            )
            if do_prints:
                print(enum_names)
            for var in re.findall(r"\b" + UPPER_VAR_RE + r"\b", args[i]):
                if do_prints:
                    print(var)
                if var.endswith(enum_names):
                    num_matching = 0
                    for n in enum_names:
                        if var.endswith(n):
                            if do_prints:
                                print(f"{enum_value_prefix}_{n}")
                            args[i] = re.sub(
                                r"\b" + var + r"(_STR)?\b", f"{enum_value_prefix}_{n}", args[i]
                            )
                            num_matching += 1
                    #assert num_matching == 1, (fn, args, i, num_matching, enum_names)
                elif re.sub(r"_STR", "", var).endswith(enum_names):
                    num_matching = 0
                    for n in enum_names:
                        if re.sub(r"_STR", "", var).endswith(n):
                            args[i] = re.sub(
                                r"\b" + var + r"(_STR)?\b", f"{enum_value_prefix}_{n}", args[i]
                            )
                            num_matching += 1
                    assert num_matching == 1, (fn, args, i, num_matching, enum_names)
        elif (
            param["type"] == "int32"
            and args[i].endswith(("_TRUE", "_FALSE"))
            and re.match(UPPER_VAR_FULL_RE, args[i])
        ):
            if param.get("grpc_type", "") == "bool":
                args[i] = args[i].rsplit("_", 1)[1].lower()
            else:
                args[i] = "BOOLEAN_" + args[i].rsplit("_", 1)[1]
        if do_prints:
            print(fn, args)
            sys.exit()
    return fn, f"(" + ", ".join(args) + ")"


def _fetch_fn(
    indent,
    lines,
    lines2,
    driver_pascal,
    functions,
    variables,
    actual_variables,
    declared_variables,
    defines,
    enums,
    acronyms,
    todos,
):
    pass
    """
    actualArraySize = 0;
    RFmxCheckWarn(RFmxNR_ModAccFetchRMSEVMPerSubcarrierMeanTrace(instrumentHandle, carrierString, timeout,
       NULL, NULL, NULL, 0, &actualArraySize));
    if (actualArraySize > 0)
    {
       RMSEVMPerSubcarrierMean[i] = (float32*)malloc(sizeof(float32) * actualArraySize);
       if (RMSEVMPerSubcarrierMean[i])
       {
          RFmxCheckWarn(RFmxNR_ModAccFetchRMSEVMPerSubcarrierMeanTrace(instrumentHandle, carrierString, timeout,
             &x0, &dx, RMSEVMPerSubcarrierMean[i], actualArraySize, NULL));
       }
       else
       {
          printf("malloc failed.\n");
          goto Error;
       }
    }"""
    lines_out = []

    line = lines.pop(0).strip()
    if line == "actualArraySize = 0;":
        line = lines.pop(0).strip()
    while re.match(r"^\w+ = \S+;$", line):
        lines_out.append(line)
        line = lines.pop(0).strip()
    assert line.startswith("RFmxCheckWarn("), line
    fn = line.split("(", 1)[1].split("(", 1)[0].replace(f"{driver_pascal}_", "", 1)
    assert re.search("Fetch[A-Z]|SpectrumRead", fn), line

    fn_metadata = functions[fn]
    params = list(fn_metadata["parameters"])
    is_sized = any("size" in p for p in params)

    queries_size = False
    if is_sized:
        mechanisms = {p["size"]["mechanism"] for p in params if "size" in p}
        assert mechanisms == {"ivi-dance-with-a-twist"}, (line, params)

        m = re.match(r"^RFmxCheckWarn\(" + f"{driver_pascal}_{fn}" + r"\((.*)\)\);$", line)
        assert m, (fn, line)
        args = re.split(", *", m.group(1))

        if fn in {"SEMFetchLowerOffsetMarginArray", "SEMFetchUpperOffsetMarginArray"}:
            queries_size = False
        else:
            queries_size = any(a == "NULL" for a in args[:-2])

    if queries_size:
        line = lines.pop(0).strip()
        assert re.match(r"^if *\( *\w+ArraySize > 0 *\)$", line), (fn, line)
        line = lines.pop(0).strip()
        assert line == "{", (fn, line)
        line = lines.pop(0).strip()
        while re.match(r"^\w+(?:\[i](?:\[j])?)? = ", line):
            # out_var = line.split(" = ", 1)[0]
            line = lines.pop(0).strip()
        # assert line.startswith("if ("), (fn, line)
        has_if = re.match(r"^if *\(", line)
        if has_if:
            line = lines.pop(0).strip()
            if_has_open_brace = line == "{"
            if if_has_open_brace:
                line = lines.pop(0).strip()
            if line.startswith("printf("):
                assert if_has_open_brace, (fn, line)
                line = lines.pop(0).strip()
                assert re.match(r"^goto +Error;$", line), (fn, line)
                line = lines.pop(0).strip()
                assert line == "}", (fn, line)
                has_if = False
                line = lines.pop(0).strip()

        assert line.startswith("RFmxCheckWarn("), (fn, line)
        fetch_line = line
        if has_if and if_has_open_brace:
            line = lines.pop(0).strip()
            assert line == "}", (fn, line)
        line = lines.pop(0).strip()
        if line == "else":
            line = lines.pop(0).strip()
            assert line == "{", (fn, line)
            line = lines.pop(0).strip()
            assert line.startswith("printf("), (fn, line)
            line = lines.pop(0).strip()
            assert line == "goto Error;", (fn, line)
            line = lines.pop(0).strip()
            assert line == "}", (fn, line)
            line = lines.pop(0).strip()
        assert line == "}", (fn, line)

        line = fetch_line

    args = line.replace(f"RFmxCheckWarn({driver_pascal}_{fn}", "", 1)
    m = re.match(r"^(\(.*\))(\);)$", args)
    assert m, line
    args, end = m.groups()
    response_class = fn + "Response"
    fn = _to_lower_snakecase(fn)  # , acronyms)

    m = re.match(r"^\((.*)\)$", args)
    assert m, (fn, args)
    args = m.group(1)
    args = re.split(", *", args)

    write_size_to_var = None
    if is_sized:
        if queries_size:
            assert args[-2].endswith("rraySize"), (fn, args)
        else:
            assert args[-2] in defines or args[-2] in variables or args[-2] in actual_variables, (
                fn,
                args,
            )
        assert args[-1] in {"NULL", "0"} or re.match("^&\w+rraySize$", args[-1]), (fn, args)
        if args[-1] not in {"NULL", "0"}:
            write_size_to_var = args[-1].lstrip("&")

            if indent == "  ":
                for l in lines2:
                    if write_size_to_var in l and re.search(r"\b" + write_size_to_var + r"\b", l):
                        break
                else:
                    declared_variables.add(write_size_to_var)
                    write_size_to_var = f"int32 {write_size_to_var}"
        del args[-2:]
        params = params[:-2]

    fetch_outputs = []
    new_args = []
    new_params = []
    for i in range(len(args)):
        if params[i]["direction"] == "in":
            new_args.append(args[i])
        else:
            fetch_outputs.append(args[i])
            new_params.append(params[i])
    args = new_args
    params = new_params
    assert all(p["direction"] == "out" for p in params), (fn, fn_metadata)

    if indent == "  ":
        response_var_decl = f"const auto {fn}_response"
    else:
        variables[f"{fn}_response"] = (response_class, f"{fn}_response", None)
        response_var_decl = f"{fn}_response"
    fn, args = _call_fn(fn, args, fn_metadata, variables, actual_variables, enums, acronyms, todos)
    # response_result_attr = fn.split("fetch_", 1)[1]
    lines_out += [
        f"{response_var_decl} = client::{fn}{args};",
        # f"EXPECT_SUCCESS(session, {fn}_response{end}",
        # f"{out_var} = {fn}_response.{response_result_attr};",
    ]
    if write_size_to_var:
        first_sized_param = [p for p in params if "size" in p][0]
        first_sized_param_name = first_sized_param.get(
            "grpc_name", _to_lower_snakecase(first_sized_param["name"])
        )
        lines_out.append(f"{write_size_to_var} = {fn}_response.{first_sized_param_name}_size();")
    checks = [
        f"  EXPECT_SUCCESS(session, {fn}_response{end}",
    ]
    for i, arg in enumerate(fetch_outputs):
        arg = arg.lstrip("&")
        param_name = params[i].get("grpc_name", _to_lower_snakecase(params[i]["name"]))
        if "size" in params[i]:
            if params[i]["type"] == "NIComplexSingle[]":
                checks.append(f"  EXPECT_EQ(0.0, {fn}_response.{param_name}(0).real());")
                checks.append(f"  EXPECT_EQ(0.0, {fn}_response.{param_name}(0).imaginary());")
            else:
                check_value = DEFAULTS[params[i]["type"][:-2]]
                checks.append(f"  EXPECT_EQ(999, {fn}_response.{param_name}_size());")
                checks.append(f"  EXPECT_EQ(999, {fn}_response.{param_name}().size());")
                checks.append(f"  EXPECT_EQ({check_value}, {fn}_response.{param_name}(0));")
        else:
            if params[i]["type"] == "NIComplexSingle":
                checks.append(f"  EXPECT_EQ(0.0, {fn}_response.{param_name}().real());")
                checks.append(f"  EXPECT_EQ(0.0, {fn}_response.{param_name}().imaginary());")
            else:
                check_value = DEFAULTS[params[i]["type"]]
                checks.append(f"  EXPECT_EQ({check_value}, {fn}_response.{param_name}());")
    return lines_out, checks


EX = r"""
//Steps:
//1. Open a new RFmx Session.
//2. Configure Frequency Reference.
//3. Configure Selected Ports.
//4. Configure basic signal properties(Center Frequency, Reference Level and External Attenuation).
//5. Configure Trigger Parameters for Digital Edge Trigger.
//6. Configure Link Direction, Frequency Range, Channel Raster and Component Carrier Spacing.
//7. Configure Bandwidth Part Subcarrier Spacing.
//8. Configure Component Carriers.
//9. Select SEM measurement and enable Traces.
//10. Configure Offsets.
//11. Configure Uplink Mask Type, or Downlink Mask, Band, gNodeB Category, Delta F_Max(Hz) and
//    Component Carrier Rated Output Power based on Link Direction.
//12. Configure Sweep Time Parameters.
//13. Configure Averaging Parameters for SEM measurement.
//14. Initiate the Measurement.
//15. Fetch SEM Measurements and Traces.
//16. Close RFmx Session.
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>
#include "niRFmxNR.h"
/* Maximum size of an error message */
#define MAX_ERROR_DESCRIPTION               4096
/* Maximum size of a selector string */
#define MAX_SELECTOR_STRING                 256
#define NUMBER_OF_COMPONENT_CARRIERS        2
#define NUMBER_OF_OFFSETS                   4
int main(int argc, char *argv[])
{
   char *resourceName = "RFSA";
   niRFmxInstrHandle instrumentHandle = NULL;
   char subblockString[MAX_SELECTOR_STRING];
   char carrierString[MAX_SELECTOR_STRING];
   char errorMessage[MAX_ERROR_DESCRIPTION] = { 0 };
   int32 error = 0, lastErrorCode = 0;
   int i = 0;
   char* selectedPorts = "";
   float64 centerFrequency = 3.5e9;                                                          /* (Hz) */
   float64 referenceLevel = 0.0;                                                             /* (dBm) */
   float64 externalAttenuation = 0.0;                                                        /* (dB) */
   char *frequencyReferenceSource = RFMXNR_VAL_ONBOARD_CLOCK_STR;
   float64 frequencyReferenceFrequency = 10e6;                                               /* (Hz) */
   int32 enableTrigger = RFMXNR_VAL_FALSE;
   char* digitalEdgeSource = RFMXNR_VAL_PXI_TRIG0_STR;
   int32 digitalEdge = RFMXNR_VAL_DIGITAL_EDGE_RISING_EDGE;
   float64 triggerDelay = 0.0;                                                               /* (s) */
   int32 linkDirection = RFMXNR_VAL_LINK_DIRECTION_UPLINK;
   int32 uplinkMaskType = RFMXNR_VAL_SEM_UPLINK_MASK_TYPE_GENERAL;
   int32 gNodeBCategory = RFMXNR_VAL_GNODEB_CATEGORY_WIDE_AREA_BASE_STATION_CATEGORY_A;
   int32 downlinkMaskType = RFMXNR_VAL_SEM_DOWNLINK_MASK_TYPE_STANDARD;
   float64 deltaFMaximum = 15.0e6;                                                           /* (Hz) */
   int32 band = 78;
   float64 componentCarrierBandwidth[NUMBER_OF_COMPONENT_CARRIERS] = { 100e6, 100e6 };       /* (Hz) */
   float64 componentCarrierFrequency[NUMBER_OF_COMPONENT_CARRIERS] = { -49.98e6, 50.01e6 };  /* (Hz) */
   float64 componentCarrierRatedOutputPower[NUMBER_OF_COMPONENT_CARRIERS] = { 0.0, 0.0 };    /* (dBm) */
   float64 offsetStartFrequency[NUMBER_OF_OFFSETS] = { 15.0e3, 1.5e6, 5.5e6, 40.3e6 };       /* (Hz) */
   float64 offsetStopFrequency[NUMBER_OF_OFFSETS] = { 985.0e3, 4.5e6, 39.3e6, 44.3e6 };      /* (Hz) */
   int32 offsetSideband[NUMBER_OF_OFFSETS] = { RFMXNR_VAL_SEM_OFFSET_SIDEBAND_BOTH,
      RFMXNR_VAL_SEM_OFFSET_SIDEBAND_BOTH,
      RFMXNR_VAL_SEM_OFFSET_SIDEBAND_BOTH,
      RFMXNR_VAL_SEM_OFFSET_SIDEBAND_BOTH };
   float64 offsetRBW[NUMBER_OF_OFFSETS] = { 10.0e3, 250.0e3, 1.0e6, 1.0e6 };                 /* (Hz) */
   int32 offsetRBWFilterType[NUMBER_OF_OFFSETS] = { RFMXNR_VAL_SEM_OFFSET_RBW_FILTER_TYPE_GAUSSIAN,
      RFMXNR_VAL_SEM_OFFSET_RBW_FILTER_TYPE_GAUSSIAN,
      RFMXNR_VAL_SEM_OFFSET_RBW_FILTER_TYPE_GAUSSIAN,
      RFMXNR_VAL_SEM_OFFSET_RBW_FILTER_TYPE_GAUSSIAN };
   int32 bandwidthIntegral[NUMBER_OF_OFFSETS] = { 3, 4, 1, 1 };
   int32 limitFailMask[NUMBER_OF_OFFSETS] = { RFMXNR_VAL_SEM_OFFSET_LIMIT_FAIL_MASK_ABSOLUTE,
      RFMXNR_VAL_SEM_OFFSET_LIMIT_FAIL_MASK_ABSOLUTE,
      RFMXNR_VAL_SEM_OFFSET_LIMIT_FAIL_MASK_ABSOLUTE,
      RFMXNR_VAL_SEM_OFFSET_LIMIT_FAIL_MASK_ABSOLUTE };
   float64 absoluteLimitStart[NUMBER_OF_OFFSETS] = { -22.5, -8.5, -11.5, -23.5 };            /* (dBm) */
   float64 absoluteLimitStop[NUMBER_OF_OFFSETS] = { -22.5, -8.5, -11.5, -23.5 };             /* (dBm) */
   float64 relativeLimitStart[NUMBER_OF_OFFSETS] = { -53.0, -53.0, -53.0, -53.0 };           /* (dB) */
   float64 relativeLimitStop[NUMBER_OF_OFFSETS] = { -60.0, -60.0, -60.0, -60.0 };            /* (dB) */
   int32 frequencyRange = RFMXNR_VAL_FREQUENCY_RANGE_RANGE1;
   int32 componentCarrierSpacingType = RFMXNR_VAL_COMPONENT_CARRIER_SPACING_TYPE_NOMINAL;
   float64 channelRaster = 15e3;                                                             /* (Hz) */
   int32 componentCarrierAtCenterFrequency = -1;
   float64 subcarrierSpacing = 30e3;                                                         /* (Hz) */
   int32 sweepTimeAuto = RFMXNR_VAL_SEM_SWEEP_TIME_AUTO_TRUE;
   float64 sweepTimeInterval = 1.0e-3;                                                       /* (s) */
   int32 averagingEnabled = RFMXNR_VAL_SEM_AVERAGING_ENABLED_FALSE;
   int32 averagingCount = 10;
   int32 averagingType = RFMXNR_VAL_SEM_AVERAGING_TYPE_RMS;
   float64 timeout = 10.0;                                                                   /* (s) */
   float64 totalAggregatedPower = 0.0;                                                       /* (dBm) */
   int32 measurementStatus = RFMXNR_VAL_SEM_MEASUREMENT_STATUS_FAIL;
   float64 *lowerOffsetMarginRelativePower = NULL;                                           /* (dB) */
   float64 *lowerOffsetMarginAbsolutePower = NULL;                                           /* (dBm) */
   float64 *lowerOffsetMargin = NULL;                                                        /* (dB) */
   float64 *lowerOffsetMarginFrequency = NULL;                                               /* (Hz) */
   int32 *lowerOffsetMeasurementStatus = NULL;
   float64 *upperOffsetMarginRelativePower = NULL;                                           /* (dB) */
   float64 *upperOffsetMarginAbsolutePower = NULL;                                           /* (dBm) */
   float64 *upperOffsetMargin = NULL;                                                        /* (dB) */
   float64 *upperOffsetMarginFrequency = NULL;                                               /* (Hz) */
   int32 *upperOffsetMeasurementStatus = NULL;
   int32 actualArraySize = 0, arraySize = 0;
   float64 x0 = 0.0, dx = 0.0;
   float32 *spectrum = NULL;
   float32 *compositeMask = NULL;
   /* Initialize a session */
   RFmxCheckWarn(RFmxNR_Initialize(resourceName, "", &instrumentHandle, NULL));
   RFmxCheckWarn(RFmxNR_CfgFrequencyReference(instrumentHandle, "", frequencyReferenceSource,
      frequencyReferenceFrequency));
   RFmxCheckWarn(RFmxNR_SetSelectedPorts(instrumentHandle, "", selectedPorts));
   RFmxCheckWarn(RFmxNR_CfgRF(instrumentHandle, "", centerFrequency, referenceLevel, externalAttenuation));
   RFmxCheckWarn(RFmxNR_CfgDigitalEdgeTrigger(instrumentHandle, "", digitalEdgeSource, digitalEdge, triggerDelay,
      enableTrigger));
   RFmxCheckWarn(RFmxNR_SetLinkDirection(instrumentHandle, "", linkDirection));
   RFmxCheckWarn(RFmxNR_SetFrequencyRange(instrumentHandle, "", frequencyRange));
   RFmxCheckWarn(RFmxNR_SetChannelRaster(instrumentHandle, "", channelRaster));
   RFmxCheckWarn(RFmxNR_SetComponentCarrierSpacingType(instrumentHandle, "", componentCarrierSpacingType));
   RFmxCheckWarn(RFmxNR_SetComponentCarrierAtCenterFrequency(instrumentHandle, "", componentCarrierAtCenterFrequency));
   strcpy_s(carrierString, sizeof("carrier::all"), "carrier::all");
   RFmxCheckWarn(RFmxNR_SetBandwidthPartSubcarrierSpacing(instrumentHandle, carrierString, subcarrierSpacing));
   RFmxCheckWarn(RFmxNR_SetNumberOfComponentCarriers(instrumentHandle, "", NUMBER_OF_COMPONENT_CARRIERS));
   RFmxCheckWarn(RFmxNR_BuildSubblockString("", 0, MAX_SELECTOR_STRING, subblockString));
   for (i = 0; i < NUMBER_OF_COMPONENT_CARRIERS; i++)
   {
      RFmxCheckWarn(RFmxNR_BuildCarrierString(subblockString, i, MAX_SELECTOR_STRING, carrierString));
      RFmxCheckWarn(RFmxNR_SetComponentCarrierBandwidth(instrumentHandle, carrierString,
         componentCarrierBandwidth[i]));
      RFmxCheckWarn(RFmxNR_SetComponentCarrierFrequency(instrumentHandle, carrierString,
         componentCarrierFrequency[i]));
   }
   RFmxCheckWarn(RFmxNR_SelectMeasurements(instrumentHandle, "", RFMXNR_VAL_SEM, RFMXNR_VAL_TRUE));
   RFmxCheckWarn(RFmxNR_SEMCfgNumberOfOffsets(instrumentHandle, "", NUMBER_OF_OFFSETS));
   RFmxCheckWarn(RFmxNR_SEMCfgOffsetFrequencyArray(instrumentHandle, "", offsetStartFrequency, offsetStopFrequency,
      offsetSideband, NUMBER_OF_OFFSETS));
   RFmxCheckWarn(RFmxNR_SEMCfgOffsetRBWFilterArray(instrumentHandle, "", offsetRBW, offsetRBWFilterType,
      NUMBER_OF_OFFSETS));
   RFmxCheckWarn(RFmxNR_SEMCfgOffsetBandwidthIntegralArray(instrumentHandle, "", bandwidthIntegral,
      NUMBER_OF_OFFSETS));
   RFmxCheckWarn(RFmxNR_SEMCfgOffsetLimitFailMaskArray(instrumentHandle, "", limitFailMask, NUMBER_OF_OFFSETS));
   RFmxCheckWarn(RFmxNR_SEMCfgOffsetAbsoluteLimitArray(instrumentHandle, "", absoluteLimitStart, absoluteLimitStop,
      NUMBER_OF_OFFSETS));
   RFmxCheckWarn(RFmxNR_SEMCfgOffsetRelativeLimitArray(instrumentHandle, "", relativeLimitStart, relativeLimitStop,
      NUMBER_OF_OFFSETS));
   if (linkDirection == RFMXNR_VAL_LINK_DIRECTION_UPLINK)
   {
      RFmxCheckWarn(RFmxNR_SEMCfgUplinkMaskType(instrumentHandle, "", uplinkMaskType));
   }
   else
   {
      RFmxCheckWarn(RFmxNR_CfggNodeBCategory(instrumentHandle, "", gNodeBCategory));
      RFmxCheckWarn(RFmxNR_SetBand(instrumentHandle, "", band));
      RFmxCheckWarn(RFmxNR_SEMSetDownlinkMaskType(instrumentHandle, "", downlinkMaskType));
      RFmxCheckWarn(RFmxNR_SEMSetDeltaFMaximum(instrumentHandle, "", deltaFMaximum));
      RFmxCheckWarn(RFmxNR_SEMCfgComponentCarrierRatedOutputPowerArray(instrumentHandle, "",
         componentCarrierRatedOutputPower, NUMBER_OF_COMPONENT_CARRIERS));
   }
   RFmxCheckWarn(RFmxNR_SEMCfgSweepTime(instrumentHandle, "", sweepTimeAuto, sweepTimeInterval));
   RFmxCheckWarn(RFmxNR_SEMCfgAveraging(instrumentHandle, "", averagingEnabled, averagingCount, averagingType));
   RFmxCheckWarn(RFmxNR_Initiate(instrumentHandle, "", ""));
   /* Fetch results */
   RFmxCheckWarn(RFmxNR_SEMFetchUpperOffsetMarginArray(instrumentHandle, "", timeout, NULL,
      NULL, NULL, NULL, NULL, 0, &actualArraySize));
   if (actualArraySize > 0)
   {
      upperOffsetMeasurementStatus = (int32 *)malloc(sizeof(int32) * actualArraySize);
      upperOffsetMargin = (float64 *)malloc(sizeof(float64) * actualArraySize);
      upperOffsetMarginFrequency = (float64 *)malloc(sizeof(float64) * actualArraySize);
      upperOffsetMarginAbsolutePower = (float64 *)malloc(sizeof(float64) * actualArraySize);
      upperOffsetMarginRelativePower = (float64 *)malloc(sizeof(float64) * actualArraySize);
      if (upperOffsetMeasurementStatus && upperOffsetMargin && upperOffsetMarginFrequency &&
         upperOffsetMarginAbsolutePower && upperOffsetMarginRelativePower)
      {
         RFmxCheckWarn(RFmxNR_SEMFetchUpperOffsetMarginArray(instrumentHandle, "", timeout,
            upperOffsetMeasurementStatus, upperOffsetMargin, upperOffsetMarginFrequency,
            upperOffsetMarginAbsolutePower, upperOffsetMarginRelativePower, actualArraySize, &arraySize));
      }
      else
      {
         printf("malloc failed.\n");
         goto Error;
      }
   }
   actualArraySize = 0;
   RFmxCheckWarn(RFmxNR_SEMFetchLowerOffsetMarginArray(instrumentHandle, "", timeout, NULL,
      NULL, NULL, NULL, NULL, 0, &actualArraySize));
   if (actualArraySize > 0)
   {
      lowerOffsetMeasurementStatus = (int32 *)malloc(sizeof(int32) * actualArraySize);
      lowerOffsetMargin = (float64 *)malloc(sizeof(float64) * actualArraySize);
      lowerOffsetMarginFrequency = (float64 *)malloc(sizeof(float64) * actualArraySize);
      lowerOffsetMarginAbsolutePower = (float64 *)malloc(sizeof(float64) * actualArraySize);
      lowerOffsetMarginRelativePower = (float64 *)malloc(sizeof(float64) * actualArraySize);
      if (lowerOffsetMeasurementStatus && lowerOffsetMargin && lowerOffsetMarginFrequency &&
         lowerOffsetMarginAbsolutePower && lowerOffsetMarginRelativePower)
      {
         RFmxCheckWarn(RFmxNR_SEMFetchLowerOffsetMarginArray(instrumentHandle, "", timeout,
            lowerOffsetMeasurementStatus, lowerOffsetMargin, lowerOffsetMarginFrequency,
            lowerOffsetMarginAbsolutePower, lowerOffsetMarginRelativePower, actualArraySize, NULL));
      }
      else
      {
         printf("malloc failed.\n");
         goto Error;
      }
   }
   RFmxCheckWarn(RFmxNR_SEMFetchTotalAggregatedPower(instrumentHandle, "", timeout, &totalAggregatedPower));
   RFmxCheckWarn(RFmxNR_SEMFetchMeasurementStatus(instrumentHandle, "", timeout, &measurementStatus));
   actualArraySize = 0;
   RFmxCheckWarn(RFmxNR_SEMFetchSpectrum(instrumentHandle, "", timeout, NULL, NULL, NULL, NULL, 0, &actualArraySize));
   if (actualArraySize > 0)
   {
      spectrum = (float32 *)malloc(sizeof(float32) * actualArraySize);
      compositeMask = (float32 *)malloc(sizeof(float32) * actualArraySize);
      if (spectrum && compositeMask)
      {
         RFmxCheckWarn(RFmxNR_SEMFetchSpectrum(instrumentHandle, "", timeout, &x0, &dx, spectrum, compositeMask,
            actualArraySize, NULL));
      }
      else
      {
         printf("malloc failed.\n");
         goto Error;
      }
   }
   printf("Total Aggregated Power (dBm)      : %lf\n", totalAggregatedPower);
   printf("Measurement Status                : %s\n",
      measurementStatus == RFMXNR_VAL_SEM_MEASUREMENT_STATUS_PASS ? "PASS" : "FAIL");
   printf("\n--------  Lower Offset Segement Measurements --------\n");
   for (i = 0; i < arraySize; i++)
   {
      printf("\nOffset  %d\n", i);
      printf("Measurement Status                : %s\n",
         lowerOffsetMeasurementStatus[i] == RFMXNR_VAL_SEM_LOWER_OFFSET_MEASUREMENT_STATUS_PASS ? "PASS" : "FAIL");
      printf("Margin (dB)                       : %lf\n", lowerOffsetMargin[i]);
      printf("Margin Frequency (Hz)             : %lf\n", lowerOffsetMarginFrequency[i]);
      printf("Margin Absolute Power (dBm)       : %lf\n", lowerOffsetMarginAbsolutePower[i]);
   }
   printf("\n--------  Upper  Offset Segement Measurements --------\n");
   for (i = 0; i < arraySize; i++)
   {
      printf("\nOffset  %d\n", i);
      printf("Measurement Status                : %s\n",
         upperOffsetMeasurementStatus[i] == RFMXNR_VAL_SEM_UPPER_OFFSET_MEASUREMENT_STATUS_PASS ? "PASS" : "FAIL");
      printf("Margin (dB)                       : %lf\n", upperOffsetMargin[i]);
      printf("Margin Frequency (Hz)             : %lf\n", upperOffsetMarginFrequency[i]);
      printf("Margin Absolute Power (dBm)       : %lf\n", upperOffsetMarginAbsolutePower[i]);
   }
Error:
   if (error)
   {
      RFmxNR_GetError(instrumentHandle, &lastErrorCode, MAX_ERROR_DESCRIPTION, errorMessage);
      if (error < 0)
         printf("\nERROR: %s\n", errorMessage);
      else
         printf("\nWARNING: %s\n", errorMessage);
   }
   if (instrumentHandle)
   {
      RFmxNR_Close(instrumentHandle, RFMXNR_VAL_FALSE);
   }
   if (lowerOffsetMeasurementStatus)
      free(lowerOffsetMeasurementStatus);
   if (lowerOffsetMarginAbsolutePower)
      free(lowerOffsetMarginAbsolutePower);
   if (lowerOffsetMarginFrequency)
      free(lowerOffsetMarginFrequency);
   if (lowerOffsetMarginRelativePower)
      free(lowerOffsetMarginRelativePower);
   if (lowerOffsetMargin)
      free(lowerOffsetMargin);
   if (upperOffsetMeasurementStatus)
      free(upperOffsetMeasurementStatus);
   if (upperOffsetMarginAbsolutePower)
      free(upperOffsetMarginAbsolutePower);
   if (upperOffsetMarginFrequency)
      free(upperOffsetMarginFrequency);
   if (upperOffsetMarginRelativePower)
      free(upperOffsetMarginRelativePower);
   if (upperOffsetMargin)
      free(upperOffsetMargin);
   if (spectrum)
      free(spectrum);
   if (compositeMask)
      free(compositeMask);
   printf("\nPress any key to exit\n");
   _getch();
   return error;
}
"""

ALL_DRIVERS = {
    "BT": "BT",
    "GSM": "GSM",
    "Instr": "RFInstr",
    "LTE": "LTE",
    "NR": "NR",
    "SpecAn": "SpecAn",
    "WCDMA": "WCDMA",
    "WLAN": "WLAN",
}


def _convert_rfmx_driver(driver="SpecAn"):
    examples_dir = pathlib.Path(
        #TODO: Update the following path to point to where the C examples are located on disk
        f"C:/dev/ni-central/src/rfmx/{ALL_DRIVERS[driver]}/RFmx{ALL_DRIVERS[driver]}C/source/examples/"
    )
    # examples_dir = examples_dir / "Advanced/"
    examples = list(examples_dir.glob("*/*.c"))
    first = True
    for ex in examples:
        assert ex.stem.lower().startswith(f"RFmx{driver}".lower()), ex.stem
        name = ex.stem[len(f"RFmx{driver}") :]
        # if "ULModAccMIMO" not in name:
        #     continue
        sys.stderr.write(f"{name}\n")
        ex_txt = ex.read_text()

        forbidden_strs = [
            "RFSGSession",
            "niRFSA_init",
            "ReadFromTDMSFile",
            "ReadWaveformsFromTDMSFile",
            "typedef struct",
            "scanf_s",
            "NFFetchYFactors",
            "CfgExternalAttenuationTable",
            "ACP_Results_1",
        ]
        # (but NR's AcpNonContiguousMultiCarrier already converted manually, despite a struct)
        forbidden_strs += [f"RFmx{d}_" for d in ALL_DRIVERS if d not in (driver, "Instr")]

        skip = None
        for s in forbidden_strs:
            if s in ex_txt:
                skip = s
                break

        if first:
            first = False
        else:
            print()
        if skip:
            sys.stderr.write(f"  Skipping due to {skip}\n")
            print(f'// NOTE: disabled due to "{skip}" in example\'s source code')
            print(
                f"TEST_F(NiRFmx{driver}DriverApiTests, DISABLED_{name}FromExample_FetchData_DataLooksReasonable)"
            )
        else:
            print(
                f"TEST_F(NiRFmx{driver}DriverApiTests, {name}FromExample_FetchData_DataLooksReasonable)"
            )
        print("{")
        if not skip:
            print(_convert(ex_txt, "RFmx" + driver))
        print("}")


_convert_rfmx_driver("GSM")
