set(SOURCES 
	include/contract/base.hpp 
	include/contract/contract.hpp
	)

add_library(contract INTERFACE)
target_include_directories(contract INTERFACE ${CMAKE_CURRENT_SOURCE_DIR}/include)
source_group(TREE ${CMAKE_CURRENT_SOURCE_DIR} FILES ${SOURCES})
