cmake_minimum_required(VERSION 3.12)

project(Foma VERSION 0.10.0)

include(FetchContent)
FetchContent_Declare(
    gzip_lib
    GIT_REPOSITORY https://github.com/madler/zlib.git
    GIT_TAG v1.2.11)
FetchContent_MakeAvailable(gzip_lib)

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
                        regex.c)

target_compile_options(foma PUBLIC -O3 -Wall -D_GNU_SOURCE -std=c99 -fvisibility=hidden -fPIC)

add_executable(flookup flookup.c)
target_link_libraries(flookup PUBLIC foma zlib)