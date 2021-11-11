#[=============================================================================[
------------------------
CreateVirtualEnvironment
------------------------
Function that creates a virtual Python environment with specific requirements.
Derived from https://schemingdeveloper.com/2020/07/02/how-to-create-a-new-python-virtual-environment-in-cmake/

Author: zoodinger
License: WTFPL

Required Arguments:
    TARGET (string):
        Target name of the virtual environment that can be used by other
        targets as a dependency.

Optional Arguments:
    REQUIREMENTS_TXT (string):
        Path to requirements.txt list to install with pip
    ENV_NAME (string)
        The name of the virtual environment. Unless otherwise specified, this
        is the same as TARGET.


Optional Output Arguments:
    OUT_PYTHON_EXE (output variable):
        Stores the path to the python executable of the virtual environment.

#]=============================================================================]

function(CreateVirtualEnvironment TARGET)
    set(KEYWORD_ARGS 
        REQUIREMENTS_TXT 
        ENV_NAME
        OUT_PYTHON_EXE
    )

    cmake_parse_arguments(ARG "" "${KEYWORD_ARGS}" "" ${ARGN})

    if (NOT ARG_ENV_NAME)
        set(ARG_ENV_NAME ${TARGET})
    endif ()

    if (NOT ARG_REQUIREMENTS_TXT)
        set(ARG_REQUIREMENTS_TXT "requirements.txt")
    endif()

    find_package(Python3 REQUIRED COMPONENTS Interpreter)

    set(VENV ${CMAKE_BINARY_DIR}/${ARG_ENV_NAME})

    if (WIN32)
        set(PYTHON_VENV_EXE ${VENV}/Scripts/python.exe)
    else ()
        set(PYTHON_VENV_EXE ${VENV}/bin/python)
    endif ()

    set(ENVIRONMENT_CREATED ${VENV}/environment.txt)
    add_custom_command(
        OUTPUT 
            ${ENVIRONMENT_CREATED}
        # Use --without-pip + ensurepip to create a venv with pip as separate steps.
        # Workaround for https://bugs.python.org/issue43749, which hopefully is fixed in cpython 3.11.
        # See also: https://github.com/actions/virtual-environments/issues/2690
        # The ensurepip in default venv creation uses the invoking python exe name. In some environments
        # this will be python3.exe instead of python.exe, which does not work in cpython venvs <=3.10.
        # This code will always use <venv>/Scripts/python.exe to call ensurepip.
        COMMAND 
            ${Python3_EXECUTABLE} -m venv --without-pip ${VENV}
        COMMAND
            ${PYTHON_VENV_EXE} -m ensurepip --upgrade --default-pip
        COMMAND
            ${PYTHON_VENV_EXE} -m pip install -r  ${ARG_REQUIREMENTS_TXT}
        COMMAND
            ${PYTHON_VENV_EXE} -m pip freeze > ${ENVIRONMENT_CREATED}
        DEPENDS 
            ${ARG_REQUIREMENTS_TXT}
        VERBATIM
    )

    add_custom_target(${TARGET} DEPENDS ${ENVIRONMENT_CREATED})

    if (ARG_OUT_PYTHON_EXE)
        set(${ARG_OUT_PYTHON_EXE} ${PYTHON_VENV_EXE} PARENT_SCOPE)
    endif ()

endfunction()
