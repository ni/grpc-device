#[=============================================================================[
------------------------
CreateVirtualEnvironment
------------------------
Function that creates a virtual Python environment with specific requirements.
Inspired by https://schemingdeveloper.com/2020/07/02/how-to-create-a-new-python-virtual-environment-in-cmake/

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
    set(
        KEYWORD_ARGS 
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
        set(PYTHON ${VENV}/Scripts/python.exe)
    else ()
        set(PYTHON ${VENV}/bin/python)
    endif ()

    set(CREATE_VENV_PY ${CMAKE_SOURCE_DIR}/cmake/createvenv.py)
    set(VENV_CREATION_COMPLETE ${VENV}/creation.complete.txt)
    add_custom_command(
        OUTPUT 
            ${VENV_CREATION_COMPLETE}
        COMMAND 
            ${Python3_EXECUTABLE} ${CREATE_VENV_PY} ${VENV} ${ARG_REQUIREMENTS_TXT}
        COMMAND
            ${CMAKE_COMMAND} -E touch ${VENV_CREATION_COMPLETE}
        DEPENDS 
            ${ARG_REQUIREMENTS_TXT} ${CREATE_VENV_PY}
        VERBATIM
    )

    add_custom_target(${TARGET} DEPENDS ${VENV_CREATION_COMPLETE})

    if (ARG_OUT_PYTHON_EXE)
        set(${ARG_OUT_PYTHON_EXE} ${PYTHON} PARENT_SCOPE)
    endif ()

endfunction()