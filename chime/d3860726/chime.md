# Todo: Consider to interrogate macOS Brew for information about installed llvm (including clang) and potentially understand how to use llvm 13 with VSCode (or other toolchain or IDE)?

```#d3860726``` *As of 2021-11-29 21:58*

[mail plain/text](mail.txt)

{% raw %}
How to "correctly" install and actually use llvm installed with Brew is still somewhat opaque.

-1) Consider to document what I think I know now about how to use the brew installed llvm clang++ in a toolchain of mine?

==&gt; This seems to be the paths I need to use llvm 13 clang++, C++ include library and libc++ static library?

> /usr/local/Cellar/llvm/13.0.0_1/bin/**clang++**  
> **/usr/local/Cellar/llvm/13.0.0_1/include/c++/v1**  
> **/usr/local/Cellar/llvm/13.0.0_1/include/c++/v1/experimental**  
> **/usr/local/opt/llvm/lib/libc++.a  
> /usr/local/opt/llvm/lib/libc++experimental.a  
> **

1) It seems I can use brew list llvm to get a listing of all installed parts of llvm?

> kjell-olovhogdal@Kjell-Olovs-Mac-Pro ~ % brew list llvm  
> /usr/local/Cellar/llvm/13.0.0_1/bin/FileCheck  
> /usr/local/Cellar/llvm/13.0.0_1/bin/analyze-build  
> /usr/local/Cellar/llvm/13.0.0_1/bin/bugpoint  
> /usr/local/Cellar/llvm/13.0.0_1/bin/c-index-test  
> /usr/local/Cellar/llvm/13.0.0_1/bin/clang  
> /usr/local/Cellar/llvm/13.0.0_1/bin/**clang++**  
> /usr/local/Cellar/llvm/13.0.0_1/bin/clang-13  
> /usr/local/Cellar/llvm/13.0.0_1/bin/clang-apply-replacements  
> /usr/local/Cellar/llvm/13.0.0_1/bin/clang-change-namespace  
> /usr/local/Cellar/llvm/13.0.0_1/bin/clang-check  
> /usr/local/Cellar/llvm/13.0.0_1/bin/clang-cl  
> /usr/local/Cellar/llvm/13.0.0_1/bin/clang-cpp  
> /usr/local/Cellar/llvm/13.0.0_1/bin/clang-doc  
> /usr/local/Cellar/llvm/13.0.0_1/bin/clang-extdef-mapping  
> /usr/local/Cellar/llvm/13.0.0_1/bin/clang-format  
> /usr/local/Cellar/llvm/13.0.0_1/bin/clang-include-fixer  
> /usr/local/Cellar/llvm/13.0.0_1/bin/clang-move  
> /usr/local/Cellar/llvm/13.0.0_1/bin/clang-offload-bundler  
> /usr/local/Cellar/llvm/13.0.0_1/bin/clang-offload-wrapper  
> /usr/local/Cellar/llvm/13.0.0_1/bin/clang-query  
> /usr/local/Cellar/llvm/13.0.0_1/bin/clang-refactor  
> /usr/local/Cellar/llvm/13.0.0_1/bin/clang-rename  
> /usr/local/Cellar/llvm/13.0.0_1/bin/clang-reorder-fields  
> /usr/local/Cellar/llvm/13.0.0_1/bin/clang-repl  
> /usr/local/Cellar/llvm/13.0.0_1/bin/clang-scan-deps  
> /usr/local/Cellar/llvm/13.0.0_1/bin/clang-tidy  
> /usr/local/Cellar/llvm/13.0.0_1/bin/clangd  
> /usr/local/Cellar/llvm/13.0.0_1/bin/clangd-xpc-test-client  
> /usr/local/Cellar/llvm/13.0.0_1/bin/count  
> /usr/local/Cellar/llvm/13.0.0_1/bin/darwin-debug  
> /usr/local/Cellar/llvm/13.0.0_1/bin/diagtool  
> /usr/local/Cellar/llvm/13.0.0_1/bin/dsymutil  
> /usr/local/Cellar/llvm/13.0.0_1/bin/find-all-symbols  
> /usr/local/Cellar/llvm/13.0.0_1/bin/git-clang-format  
> /usr/local/Cellar/llvm/13.0.0_1/bin/hmaptool  
> /usr/local/Cellar/llvm/13.0.0_1/bin/intercept-build  
> /usr/local/Cellar/llvm/13.0.0_1/bin/ld.lld  
> /usr/local/Cellar/llvm/13.0.0_1/bin/ld64.lld  
> /usr/local/Cellar/llvm/13.0.0_1/bin/ld64.lld.darwinnew  
> /usr/local/Cellar/llvm/13.0.0_1/bin/ld64.lld.darwinold  
> /usr/local/Cellar/llvm/13.0.0_1/bin/llc  
> /usr/local/Cellar/llvm/13.0.0_1/bin/lld  
> /usr/local/Cellar/llvm/13.0.0_1/bin/lld-link  
> /usr/local/Cellar/llvm/13.0.0_1/bin/lldb  
> /usr/local/Cellar/llvm/13.0.0_1/bin/lldb-argdumper  
> /usr/local/Cellar/llvm/13.0.0_1/bin/lldb-instr  
> /usr/local/Cellar/llvm/13.0.0_1/bin/lldb-server  
> /usr/local/Cellar/llvm/13.0.0_1/bin/lldb-vscode  
> /usr/local/Cellar/llvm/13.0.0_1/bin/lli  
> /usr/local/Cellar/llvm/13.0.0_1/bin/lli-child-target  
> /usr/local/Cellar/llvm/13.0.0_1/bin/llvm-PerfectShuffle  
> /usr/local/Cellar/llvm/13.0.0_1/bin/llvm-addr2line  
> /usr/local/Cellar/llvm/13.0.0_1/bin/llvm-ar  
> /usr/local/Cellar/llvm/13.0.0_1/bin/llvm-as  
> /usr/local/Cellar/llvm/13.0.0_1/bin/llvm-bcanalyzer  
> /usr/local/Cellar/llvm/13.0.0_1/bin/llvm-bitcode-strip  
> /usr/local/Cellar/llvm/13.0.0_1/bin/llvm-c-test  
> /usr/local/Cellar/llvm/13.0.0_1/bin/llvm-cat  
> /usr/local/Cellar/llvm/13.0.0_1/bin/llvm-cfi-verify  
> /usr/local/Cellar/llvm/13.0.0_1/bin/llvm-config  
> /usr/local/Cellar/llvm/13.0.0_1/bin/llvm-cov  
> /usr/local/Cellar/llvm/13.0.0_1/bin/llvm-cvtres  
> /usr/local/Cellar/llvm/13.0.0_1/bin/llvm-cxxdump  
> /usr/local/Cellar/llvm/13.0.0_1/bin/llvm-cxxfilt  
> /usr/local/Cellar/llvm/13.0.0_1/bin/llvm-cxxmap  
> /usr/local/Cellar/llvm/13.0.0_1/bin/llvm-diff  
> /usr/local/Cellar/llvm/13.0.0_1/bin/llvm-dis  
> /usr/local/Cellar/llvm/13.0.0_1/bin/llvm-dlltool  
> /usr/local/Cellar/llvm/13.0.0_1/bin/llvm-dwarfdump  
> /usr/local/Cellar/llvm/13.0.0_1/bin/llvm-dwp  
> /usr/local/Cellar/llvm/13.0.0_1/bin/llvm-exegesis  
> /usr/local/Cellar/llvm/13.0.0_1/bin/llvm-extract  
> /usr/local/Cellar/llvm/13.0.0_1/bin/llvm-gsymutil  
> /usr/local/Cellar/llvm/13.0.0_1/bin/llvm-ifs  
> /usr/local/Cellar/llvm/13.0.0_1/bin/llvm-install-name-tool  
> /usr/local/Cellar/llvm/13.0.0_1/bin/llvm-jitlink  
> /usr/local/Cellar/llvm/13.0.0_1/bin/llvm-jitlink-executor  
> /usr/local/Cellar/llvm/13.0.0_1/bin/llvm-lib  
> /usr/local/Cellar/llvm/13.0.0_1/bin/llvm-libtool-darwin  
> /usr/local/Cellar/llvm/13.0.0_1/bin/llvm-link  
> /usr/local/Cellar/llvm/13.0.0_1/bin/llvm-lipo  
> /usr/local/Cellar/llvm/13.0.0_1/bin/llvm-lto  
> /usr/local/Cellar/llvm/13.0.0_1/bin/llvm-lto2  
> /usr/local/Cellar/llvm/13.0.0_1/bin/llvm-mc  
> /usr/local/Cellar/llvm/13.0.0_1/bin/llvm-mca  
> /usr/local/Cellar/llvm/13.0.0_1/bin/llvm-ml  
> /usr/local/Cellar/llvm/13.0.0_1/bin/llvm-modextract  
> /usr/local/Cellar/llvm/13.0.0_1/bin/llvm-mt  
> /usr/local/Cellar/llvm/13.0.0_1/bin/llvm-nm  
> /usr/local/Cellar/llvm/13.0.0_1/bin/llvm-objcopy  
> /usr/local/Cellar/llvm/13.0.0_1/bin/llvm-objdump  
> /usr/local/Cellar/llvm/13.0.0_1/bin/llvm-opt-report  
> /usr/local/Cellar/llvm/13.0.0_1/bin/llvm-otool  
> /usr/local/Cellar/llvm/13.0.0_1/bin/llvm-pdbutil  
> /usr/local/Cellar/llvm/13.0.0_1/bin/llvm-profdata  
> /usr/local/Cellar/llvm/13.0.0_1/bin/llvm-profgen  
> /usr/local/Cellar/llvm/13.0.0_1/bin/llvm-ranlib  
> /usr/local/Cellar/llvm/13.0.0_1/bin/llvm-rc  
> /usr/local/Cellar/llvm/13.0.0_1/bin/llvm-readelf  
> /usr/local/Cellar/llvm/13.0.0_1/bin/llvm-readobj  
> /usr/local/Cellar/llvm/13.0.0_1/bin/llvm-reduce  
> /usr/local/Cellar/llvm/13.0.0_1/bin/llvm-rtdyld  
> /usr/local/Cellar/llvm/13.0.0_1/bin/llvm-sim  
> /usr/local/Cellar/llvm/13.0.0_1/bin/llvm-size  
> /usr/local/Cellar/llvm/13.0.0_1/bin/llvm-split  
> /usr/local/Cellar/llvm/13.0.0_1/bin/llvm-stress  
> /usr/local/Cellar/llvm/13.0.0_1/bin/llvm-strings  
> /usr/local/Cellar/llvm/13.0.0_1/bin/llvm-strip  
> /usr/local/Cellar/llvm/13.0.0_1/bin/llvm-symbolizer  
> /usr/local/Cellar/llvm/13.0.0_1/bin/llvm-tapi-diff  
> /usr/local/Cellar/llvm/13.0.0_1/bin/llvm-tblgen  
> /usr/local/Cellar/llvm/13.0.0_1/bin/llvm-undname  
> /usr/local/Cellar/llvm/13.0.0_1/bin/llvm-windres  
> /usr/local/Cellar/llvm/13.0.0_1/bin/llvm-xray  
> /usr/local/Cellar/llvm/13.0.0_1/bin/mlir-cpu-runner  
> /usr/local/Cellar/llvm/13.0.0_1/bin/mlir-linalg-ods-gen  
> /usr/local/Cellar/llvm/13.0.0_1/bin/mlir-linalg-ods-yaml-gen  
> /usr/local/Cellar/llvm/13.0.0_1/bin/mlir-lsp-server  
> /usr/local/Cellar/llvm/13.0.0_1/bin/mlir-opt  
> /usr/local/Cellar/llvm/13.0.0_1/bin/mlir-reduce  
> /usr/local/Cellar/llvm/13.0.0_1/bin/mlir-tblgen  
> /usr/local/Cellar/llvm/13.0.0_1/bin/mlir-translate  
> /usr/local/Cellar/llvm/13.0.0_1/bin/modularize  
> /usr/local/Cellar/llvm/13.0.0_1/bin/not  
> /usr/local/Cellar/llvm/13.0.0_1/bin/obj2yaml  
> /usr/local/Cellar/llvm/13.0.0_1/bin/opt  
> /usr/local/Cellar/llvm/13.0.0_1/bin/pp-trace  
> /usr/local/Cellar/llvm/13.0.0_1/bin/run-clang-tidy  
> /usr/local/Cellar/llvm/13.0.0_1/bin/sancov  
> /usr/local/Cellar/llvm/13.0.0_1/bin/sanstats  
> /usr/local/Cellar/llvm/13.0.0_1/bin/scan-build  
> /usr/local/Cellar/llvm/13.0.0_1/bin/scan-build-py  
> /usr/local/Cellar/llvm/13.0.0_1/bin/scan-view  
> /usr/local/Cellar/llvm/13.0.0_1/bin/set-xcode-analyzer  
> /usr/local/Cellar/llvm/13.0.0_1/bin/split-file  
> /usr/local/Cellar/llvm/13.0.0_1/bin/verify-uselistorder  
> /usr/local/Cellar/llvm/13.0.0_1/bin/wasm-ld  
> /usr/local/Cellar/llvm/13.0.0_1/bin/yaml-bench  
> /usr/local/Cellar/llvm/13.0.0_1/bin/yaml2obj  
> /usr/local/Cellar/llvm/13.0.0_1/**include/c++/** (389 files)  
> /usr/local/Cellar/llvm/13.0.0_1/include/clang/ (647 files)  
> /usr/local/Cellar/llvm/13.0.0_1/include/clang-c/ (10 files)  
> /usr/local/Cellar/llvm/13.0.0_1/include/clang-tidy/ (319 files)  
> /usr/local/Cellar/llvm/13.0.0_1/include/lld/ (35 files)  
> /usr/local/Cellar/llvm/13.0.0_1/include/lldb/ (505 files)  
> /usr/local/Cellar/llvm/13.0.0_1/include/llvm/ (1627 files)  
> /usr/local/Cellar/llvm/13.0.0_1/include/llvm-c/ (35 files)  
> /usr/local/Cellar/llvm/13.0.0_1/include/mlir/ (779 files)  
> /usr/local/Cellar/llvm/13.0.0_1/include/mlir-c/ (24 files)  
> /usr/local/Cellar/llvm/13.0.0_1/include/polly/ (116 files)  
> /usr/local/Cellar/llvm/13.0.0_1/lib/libClangdXPCLib.dylib  
> /usr/local/Cellar/llvm/13.0.0_1/lib/libLLVM-C.dylib  
> /usr/local/Cellar/llvm/13.0.0_1/lib/libLLVM.dylib  
> /usr/local/Cellar/llvm/13.0.0_1/lib/libLTO.dylib  
> /usr/local/Cellar/llvm/13.0.0_1/lib/libMLIR.dylib  
> /usr/local/Cellar/llvm/13.0.0_1/lib/libRemarks.dylib  
> /usr/local/Cellar/llvm/13.0.0_1/lib/libc++.1.0.dylib  
> /usr/local/Cellar/llvm/13.0.0_1/lib/libc++abi.1.0.dylib  
> /usr/local/Cellar/llvm/13.0.0_1/lib/libclang-cpp.dylib  
> /usr/local/Cellar/llvm/13.0.0_1/lib/libclang.dylib  
> /usr/local/Cellar/llvm/13.0.0_1/lib/liblldb.13.0.0.dylib  
> /usr/local/Cellar/llvm/13.0.0_1/lib/libmlir_async_runtime.dylib  
> /usr/local/Cellar/llvm/13.0.0_1/lib/libmlir_c_runner_utils.dylib  
> /usr/local/Cellar/llvm/13.0.0_1/lib/libmlir_runner_utils.dylib  
> /usr/local/Cellar/llvm/13.0.0_1/lib/libomp.dylib  
> /usr/local/Cellar/llvm/13.0.0_1/lib/libunwind.1.0.dylib  
> /usr/local/Cellar/llvm/13.0.0_1/lib/clang/ (210 files)  
> /usr/local/Cellar/llvm/13.0.0_1/lib/cmake/ (50 files)  
> /usr/local/Cellar/llvm/13.0.0_1/lib/libear/ (3 files)  
> /usr/local/Cellar/llvm/13.0.0_1/lib/libscanbuild/ (11 files)  
> /usr/local/Cellar/llvm/13.0.0_1/lib/python3.9/ (18 files)  
> /usr/local/Cellar/llvm/13.0.0_1/lib/ (424 other files)  
> /usr/local/Cellar/llvm/13.0.0_1/libexec/python3.9/ (27 files)  
> /usr/local/Cellar/llvm/13.0.0_1/libexec/ (6 files)  
> /usr/local/Cellar/llvm/13.0.0_1/share/clang/ (11 files)  
> /usr/local/Cellar/llvm/13.0.0_1/share/emacs/ (6 files)  
> /usr/local/Cellar/llvm/13.0.0_1/share/man/man1/scan-build.1  
> /usr/local/Cellar/llvm/13.0.0_1/share/opt-viewer/ (6 files)  
> /usr/local/Cellar/llvm/13.0.0_1/share/scan-build/ (2 files)  
> /usr/local/Cellar/llvm/13.0.0_1/share/scan-view/ (4 files)  
> /usr/local/Cellar/llvm/13.0.0_1/share/vim/ (16 files)  
> /usr/local/Cellar/llvm/13.0.0_1/Toolchains/LLVM13.0.0.xctoolchain/ (5402 files)  
> kjell-olovhogdal@Kjell-Olovs-Mac-Pro ~ %

2) It seems llvm installed with brew comes with c++ headers for the C++ standard library in /usr/local/Cellar/llvm/13.0.0_1/include/c++/v1 ?

> kjell-olovhogdal@Kjell-Olovs-Mac-Pro LLVM13.0.0.xctoolchain % tree /usr/local/Cellar/llvm/13.0.0_1/include/c++/  
> /usr/local/Cellar/llvm/13.0.0_1/include/c++/  
> └── v1  
> ├── __algorithm  
> │ ├── adjacent_find.h  
> │ ├── all_of.h  
> │ ├── any_of.h  
> │ ├── binary_search.h  
> │ ├── clamp.h  
> │ ├── comp.h  
> │ ├── comp_ref_type.h  
> │ ├── copy.h  
> │ ├── copy_backward.h  
> │ ├── copy_if.h  
> │ ├── copy_n.h  
> │ ├── count.h  
> │ ├── count_if.h  
> │ ├── equal.h  
> │ ├── equal_range.h  
> │ ├── fill.h  
> │ ├── fill_n.h  
> │ ├── find.h  
> │ ├── find_end.h  
> │ ├── find_first_of.h  
> │ ├── find_if.h  
> │ ├── find_if_not.h  
> │ ├── for_each.h  
> │ ├── for_each_n.h  
> │ ├── generate.h  
> │ ├── generate_n.h  
> │ ├── half_positive.h  
> │ ├── includes.h  
> │ ├── inplace_merge.h  
> │ ├── is_heap.h  
> │ ├── is_heap_until.h  
> │ ├── is_partitioned.h  
> │ ├── is_permutation.h  
> │ ├── is_sorted.h  
> │ ├── is_sorted_until.h  
> │ ├── iter_swap.h  
> │ ├── lexicographical_compare.h  
> │ ├── lower_bound.h  
> │ ├── make_heap.h  
> │ ├── max.h  
> │ ├── max_element.h  
> │ ├── merge.h  
> │ ├── min.h  
> │ ├── min_element.h  
> │ ├── minmax.h  
> │ ├── minmax_element.h  
> │ ├── mismatch.h  
> │ ├── move.h  
> │ ├── move_backward.h  
> │ ├── next_permutation.h  
> │ ├── none_of.h  
> │ ├── nth_element.h  
> │ ├── partial_sort.h  
> │ ├── partial_sort_copy.h  
> │ ├── partition.h  
> │ ├── partition_copy.h  
> │ ├── partition_point.h  
> │ ├── pop_heap.h  
> │ ├── prev_permutation.h  
> │ ├── push_heap.h  
> │ ├── remove.h  
> │ ├── remove_copy.h  
> │ ├── remove_copy_if.h  
> │ ├── remove_if.h  
> │ ├── replace.h  
> │ ├── replace_copy.h  
> │ ├── replace_copy_if.h  
> │ ├── replace_if.h  
> │ ├── reverse.h  
> │ ├── reverse_copy.h  
> │ ├── rotate.h  
> │ ├── rotate_copy.h  
> │ ├── sample.h  
> │ ├── search.h  
> │ ├── search_n.h  
> │ ├── set_difference.h  
> │ ├── set_intersection.h  
> │ ├── set_symmetric_difference.h  
> │ ├── set_union.h  
> │ ├── shift_left.h  
> │ ├── shift_right.h  
> │ ├── shuffle.h  
> │ ├── sift_down.h  
> │ ├── sort.h  
> │ ├── sort_heap.h  
> │ ├── stable_partition.h  
> │ ├── stable_sort.h  
> │ ├── swap_ranges.h  
> │ ├── transform.h  
> │ ├── unique.h  
> │ ├── unique_copy.h  
> │ ├── unwrap_iter.h  
> │ └── upper_bound.h  
> ├── __availability  
> ├── __bit_reference  
> ├── __bits  
> ├── __bsd_locale_defaults.h  
> ├── __bsd_locale_fallbacks.h  
> ├── __config  
> ├── __config_site  
> ├── __cxxabi_config.h  
> ├── __debug  
> ├── __errc  
> ├── __format  
> │ ├── format_error.h  
> │ └── format_parse_context.h  
> ├── __function_like.h  
> ├── __functional  
> │ ├── binary_function.h  
> │ ├── binary_negate.h  
> │ ├── bind.h  
> │ ├── bind_front.h  
> │ ├── binder1st.h  
> │ ├── binder2nd.h  
> │ ├── default_searcher.h  
> │ ├── function.h  
> │ ├── hash.h  
> │ ├── identity.h  
> │ ├── invoke.h  
> │ ├── is_transparent.h  
> │ ├── mem_fn.h  
> │ ├── mem_fun_ref.h  
> │ ├── not_fn.h  
> │ ├── operations.h  
> │ ├── perfect_forward.h  
> │ ├── pointer_to_binary_function.h  
> │ ├── pointer_to_unary_function.h  
> │ ├── ranges_operations.h  
> │ ├── reference_wrapper.h  
> │ ├── unary_function.h  
> │ ├── unary_negate.h  
> │ ├── unwrap_ref.h  
> │ └── weak_result_type.h  
> ├── __functional_base  
> ├── __hash_table  
> ├── __iterator  
> │ ├── access.h  
> │ ├── advance.h  
> │ ├── back_insert_iterator.h  
> │ ├── common_iterator.h  
> │ ├── concepts.h  
> │ ├── counted_iterator.h  
> │ ├── data.h  
> │ ├── default_sentinel.h  
> │ ├── distance.h  
> │ ├── empty.h  
> │ ├── erase_if_container.h  
> │ ├── front_insert_iterator.h  
> │ ├── incrementable_traits.h  
> │ ├── insert_iterator.h  
> │ ├── istream_iterator.h  
> │ ├── istreambuf_iterator.h  
> │ ├── iter_move.h  
> │ ├── iter_swap.h  
> │ ├── iterator.h  
> │ ├── iterator_traits.h  
> │ ├── move_iterator.h  
> │ ├── next.h  
> │ ├── ostream_iterator.h  
> │ ├── ostreambuf_iterator.h  
> │ ├── prev.h  
> │ ├── projected.h  
> │ ├── readable_traits.h  
> │ ├── reverse_access.h  
> │ ├── reverse_iterator.h  
> │ ├── size.h  
> │ └── wrap_iter.h  
> ├── __libcpp_version  
> ├── __locale  
> ├── __memory  
> │ ├── addressof.h  
> │ ├── allocation_guard.h  
> │ ├── allocator.h  
> │ ├── allocator_arg_t.h  
> │ ├── allocator_traits.h  
> │ ├── auto_ptr.h  
> │ ├── compressed_pair.h  
> │ ├── construct_at.h  
> │ ├── pointer_safety.h  
> │ ├── pointer_traits.h  
> │ ├── raw_storage_iterator.h  
> │ ├── shared_ptr.h  
> │ ├── temporary_buffer.h  
> │ ├── uninitialized_algorithms.h  
> │ ├── unique_ptr.h  
> │ └── uses_allocator.h  
> ├── __mutex_base  
> ├── __node_handle  
> ├── __nullptr  
> ├── __random  
> │ └── uniform_int_distribution.h  
> ├── __ranges  
> │ ├── access.h  
> │ ├── all.h  
> │ ├── common_view.h  
> │ ├── concepts.h  
> │ ├── copyable_box.h  
> │ ├── dangling.h  
> │ ├── data.h  
> │ ├── drop_view.h  
> │ ├── empty.h  
> │ ├── empty_view.h  
> │ ├── enable_borrowed_range.h  
> │ ├── enable_view.h  
> │ ├── non_propagating_cache.h  
> │ ├── ref_view.h  
> │ ├── size.h  
> │ ├── subrange.h  
> │ ├── transform_view.h  
> │ └── view_interface.h  
> ├── __split_buffer  
> ├── __std_stream  
> ├── __string  
> ├── __support  
> │ ├── android  
> │ │ └── locale_bionic.h  
> │ ├── fuchsia  
> │ │ └── xlocale.h  
> │ ├── ibm  
> │ │ ├── gettod_zos.h  
> │ │ ├── limits.h  
> │ │ ├── locale_mgmt_aix.h  
> │ │ ├── locale_mgmt_zos.h  
> │ │ ├── nanosleep.h  
> │ │ ├── support.h  
> │ │ └── xlocale.h  
> │ ├── musl  
> │ │ └── xlocale.h  
> │ ├── newlib  
> │ │ └── xlocale.h  
> │ ├── nuttx  
> │ │ └── xlocale.h  
> │ ├── openbsd  
> │ │ └── xlocale.h  
> │ ├── solaris  
> │ │ ├── floatingpoint.h  
> │ │ ├── wchar.h  
> │ │ └── xlocale.h  
> │ ├── win32  
> │ │ ├── limits_msvc_win32.h  
> │ │ └── locale_win32.h  
> │ └── xlocale  
> │ ├── __nop_locale_mgmt.h  
> │ ├── __posix_l_fallback.h  
> │ └── __strtonum_fallback.h  
> ├── __threading_support  
> ├── __tree  
> ├── __tuple  
> ├── __undef_macros  
> ├── __utility  
> │ ├── __decay_copy.h  
> │ ├── as_const.h  
> │ ├── cmp.h  
> │ ├── declval.h  
> │ ├── exchange.h  
> │ ├── forward.h  
> │ ├── in_place.h  
> │ ├── integer_sequence.h  
> │ ├── move.h  
> │ ├── pair.h  
> │ ├── piecewise_construct.h  
> │ ├── rel_ops.h  
> │ ├── swap.h  
> │ └── to_underlying.h  
> ├── __variant  
> │ └── monostate.h  
> **├── algorithm**  
> **├── any**  
> **├── array**  
> **├── atomic**  
> **├── barrier**  
> **├── bit**  
> **├── bitset**  
> **├── cassert**  
> **├── ccomplex**  
> **├── cctype**  
> **├── cerrno**  
> **├── cfenv**  
> **├── cfloat**  
> **├── charconv**  
> **├── chrono**  
> **├── cinttypes**  
> **├── ciso646**  
> **├── climits**  
> **├── clocale**  
> **├── cmath**  
> **├── codecvt**  
> **├── compare**  
> **├── complex**  
> **├── complex.h**  
> **├── concepts**  
> **├── condition_variable**  
> **├── csetjmp**  
> **├── csignal**  
> **├── cstdarg**  
> **├── cstdbool**  
> **├── cstddef**  
> **├── cstdint**  
> **├── cstdio**  
> **├── cstdlib**  
> **├── cstring**  
> **├── ctgmath**  
> **├── ctime**  
> **├── ctype.h**  
> **├── cwchar**  
> **├── cwctype**  
> **├── cxxabi.h**  
> **├── deque**  
> **├── errno.h**  
> **├── exception**  
> **├── execution**  
> ├── experimental  
> │ ├── __config  
> │ ├── __memory  
> │ ├── algorithm  
> │ ├── coroutine  
> │ ├── deque  
> │ ├── filesystem  
> │ ├── forward_list  
> │ ├── functional  
> │ ├── iterator  
> │ ├── list  
> │ ├── map  
> │ ├── memory_resource  
> │ ├── propagate_const  
> │ ├── regex  
> │ ├── set  
> │ ├── simd  
> │ ├── string  
> │ ├── type_traits  
> │ ├── unordered_map  
> │ ├── unordered_set  
> │ ├── utility  
> │ └── vector  
> ├── ext  
> │ ├── __hash  
> │ ├── hash_map  
> │ └── hash_set  
> **├── fenv.h**  
> **├── filesystem**  
> **├── float.h**  
> **├── format**  
> **├── forward_list**  
> **├── fstream**  
> **├── functional**  
> **├── future**  
> **├── initializer_list**  
> **├── inttypes.h**  
> **├── iomanip**  
> **├── ios**  
> **├── iosfwd**  
> **├── iostream**  
> **├── istream**  
> **├── iterator**  
> **├── latch**  
> **├── limits**  
> **├── limits.h**  
> **├── list**  
> **├── locale**  
> **├── locale.h**  
> **├── map**  
> **├── math.h**  
> **├── memory**  
> **├── module.modulemap**  
> **├── mutex**  
> **├── new**  
> **├── numbers**  
> **├── numeric**  
> **├── optional**  
> **├── ostream**  
> **├── queue**  
> **├── random**  
> **├── ranges**  
> **├── ratio**  
> **├── regex**  
> **├── scoped_allocator**  
> **├── semaphore**  
> **├── set**  
> **├── setjmp.h**  
> **├── shared_mutex**  
> **├── span**  
> **├── sstream**  
> **├── stack**  
> **├── stdbool.h**  
> **├── stddef.h**  
> **├── stdexcept**  
> **├── stdint.h**  
> **├── stdio.h**  
> **├── stdlib.h**  
> **├── streambuf**  
> **├── string**  
> **├── string.h**  
> **├── string_view**  
> **├── strstream**  
> **├── system_error**  
> **├── tgmath.h**  
> **├── thread**  
> **├── tuple**  
> **├── type_traits**  
> **├── typeindex**  
> **├── typeinfo**  
> **├── unordered_map**  
> **├── unordered_set**  
> **├── utility**  
> **├── valarray**  
> **├── variant**  
> **├── vector**  
> **├── version**  
> **├── wchar.h**  
> **└── wctype.h**

> 23 directories, 389 files  
> kjell-olovhogdal@Kjell-Olovs-Mac-Pro LLVM13.0.0.xctoolchain %

==&gt; It seems that actual C++ standard library is in /usr/local/opt/llvm/lib?

> kjell-olovhogdal@Kjell-Olovs-Mac-Pro LLVM13.0.0.xctoolchain % find /usr/local/opt/llvm/lib/libc++\*  
> /usr/local/opt/llvm/lib/libc++.1.0.dylib  
> /usr/local/opt/llvm/lib/libc++.1.dylib  
> /usr/local/opt/llvm/lib/libc++.a  
> /usr/local/opt/llvm/lib/libc++.dylib  
> /usr/local/opt/llvm/lib/libc++abi.1.0.dylib  
> /usr/local/opt/llvm/lib/libc++abi.1.dylib  
> /usr/local/opt/llvm/lib/libc++abi.a  
> /usr/local/opt/llvm/lib/libc++abi.dylib  
> /usr/local/opt/llvm/lib/libc++experimental.a  
> kjell-olovhogdal@Kjell-Olovs-Mac-Pro LLVM13.0.0.xctoolchain %

3) It seems I can use **brew info** to get some valuable information on where llvm is installed and how to use it?

NOTE: NO! This information is about interfacing parts of the llvm itself - NOT to use in a tool chain to build C++ code!

==&gt; It seems llvm is NOT symlinked (To NOT interfere with macOS installed versions of llvm tools)?

> kjell-olovhogdal@Kjell-Olovs-Mac-Pro ~ % **brew info llvm**  
> llvm: stable 13.0.0 (bottled), HEAD &#91;keg-only&#93;  
> Next-gen compiler infrastructure  
> <https://llvm.org/>  
> /usr/local/Cellar/llvm/13.0.0_1 (10,841 files, 1.8GB)  
> Poured from bottle on 2021-11-27 at 13:43:45  
> From: <https://github.com/Homebrew/homebrew-core/blob/HEAD/Formula/llvm.rb>  
> License: Apache-2.0 with LLVM-exception  
> ==&gt; **Dependencies**  
> Build: **cmake ****✘**, **swig ****✔**  
> Required: **python@3.9 ****✔**  
> ==&gt; **Options**  
> --HEAD  
> Install HEAD version  
> ==&gt; **Caveats**  
> To use the bundled libc++ please add the following LDFLAGS:  
> LDFLAGS="-L/usr/local/opt/llvm/lib -Wl,-rpath,/usr/local/opt/llvm/lib"

> llvm is keg-only, which means it was not symlinked into /usr/local,  
> because macOS already provides this software and installing another version in  
> parallel can cause all kinds of trouble.

> If you need to have llvm first in your PATH, run:  
> echo 'export PATH="/usr/local/opt/llvm/bin:$PATH"' &gt;&gt; ~/.zshrc

> For compilers to find llvm you may need to set:  
> export LDFLAGS="-L/usr/local/opt/llvm/lib"  
> export CPPFLAGS="-I/usr/local/opt/llvm/include"

> ==&gt; **Analytics**  
> install: 31,775 (30 days), 92,640 (90 days), 291,791 (365 days)  
> install-on-request: 17,482 (30 days), 59,485 (90 days), 209,445 (365 days)  
> build-error: 2,334 (30 days)  
> kjell-olovhogdal@Kjell-Olovs-Mac-Pro ~ %

==&gt; It seems I do NOT have Brew-installed llvm in the path?

> kjell-olovhogdal@Kjell-Olovs-Mac-Pro ~ % echo $path  
> /usr/local/bin /usr/bin /bin /usr/sbin /sbin /Library/TeX/texbin /Library/Apple/usr/bin  
> kjell-olovhogdal@Kjell-Olovs-Mac-Pro ~ %

==&gt; It seems Brew uses /usr/local/opt/llvm/ for links to installed llvm?

...

{% endraw %}
