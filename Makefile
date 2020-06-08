clean:
	@REPO=${HOME}/github/example
	@find $$REPO -iname ".ccls-cache" -exec rm -r {} \;
	@find $$REPO -iname "*~" -exec rm -r {} \;
#	read -p "Cleaning directory : $(REPO)"
#       find $(HOME)/github/examples
#       $(MAKE) -C ./mainsrc/BST/check_bst/ clean
#       $(MAKE) -C ./mainsrc/BST/convert_sorted_array_to_bst/ clean
#       $(MAKE) -C ./mainsrc/BST/delete_node_from_bst/ clean
#       $(MAKE) -C ./mainsrc/LL_PROBLEMS/LL_one_gap_pair_swap/ clean
#       $(MAKE) -C ./mainsrc/LL_PROBLEMS/LL_pair_reverse/ clean
#       $(MAKE) -C ./mainsrc/LL_PROBLEMS/LL_reverse/ clean
#       $(MAKE) -C ./mainsrc/MATRIX/shortest_distance/ clean
#       $(MAKE) -C ./mainsrc/MATRIX/shortest_distance_class/ clean
#       $(MAKE) -C ./mainsrc/MISC/const_cast/ clean
#       $(MAKE) -C ./mainsrc/MISC/dynamic_cast/ clean
#       $(MAKE) -C ./mainsrc/MISC/explicit_constructor/ clean
#       $(MAKE) -C ./mainsrc/MISC/fun_ptr_example_1/ clean
#       $(MAKE) -C ./mainsrc/MISC/io_redirection_example/ clean
#       $(MAKE) -C ./mainsrc/MISC/linker_test1/ clean
#       $(MAKE) -C ./mainsrc/MISC/map_cpp/ clean
#       $(MAKE) -C ./mainsrc/MISC/pthread_barrier_Example/ clean
#       $(MAKE) -C ./mainsrc/MISC/sizeof_type/ clean
#       $(MAKE) -C ./mainsrc/MISC/strtok_implementation/ clean
#       $(MAKE) -C ./mainsrc/MISC/temtest_cpp/ clean
#       $(MAKE) -C ./mainsrc/MISC/vector_iterator/ clean
#       $(MAKE) -C ./mainsrc/SORT/counting_sort/ clean
#       $(MAKE) -C ./mainsrc/SORT/heapify/ clean
