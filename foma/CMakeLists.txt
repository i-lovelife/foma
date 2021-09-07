include(FetchContent)
FetchContent_Declare(
    gzip_lib
    GIT_REPOSITORY https://github.com/madler/zlib.git
    GIT_TAG v1.2.11)
FetchContent_GetProperties(gzip_lib)
if(NOT gzip_lib_POPULATED)
    FetchContent_Populate(gzip_lib)
    file(COPY ${gzip_lib_SOURCE_DIR}/zlib.h DESTINATION ${gzip_lib_BINARY_DIR})
    add_subdirectory(${gzip_lib_SOURCE_DIR} ${gzip_lib_BINARY_DIR})
endif()

add_library(foma STATIC int_stack.c 
                        define.c 
                        determinize.c 
                        apply.c 
                        rewrite.c 
                        lexcread.c 
                        topsort.c 
                        flags.c 
                        minimize.c 
                        reverse.c 
                        extract.c 
                        sigma.c 
                        io.c 
                        structures.c 
                        constructions.c 
                        coaccessible.c 
                        utf8.c 
                        spelling.c 
                        dynarray.c 
                        mem.c 
                        stringhash.c 
                        trie.c 
                        lex.lexc.c 
                        lex.yy.c 
                        lex.cmatrix.c 
                        regex.c
                        fomalib.h
                        fomalibconf.h
                        foma.h
                        lexc.h
                        regex.h)

target_link_libraries(foma zlibstatic)

target_compile_options(foma PRIVATE -O3 -Wall -D_GNU_SOURCE -std=c99 -fvisibility=hidden -fPIC)
target_include_directories(foma PUBLIC ${gzip_lib_BINARY_DIR}/)

add_executable(flookup flookup.c)
target_link_libraries(flookup PUBLIC foma)