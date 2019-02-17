include(CheckIPOSupported)
check_ipo_supported(RESULT result)

function(configure_library library)
    if(result)
        set_target_properties(${library} PROPERTIES INTERPROCEDURAL_OPTIMIZATION_Debug OFF)
        set_target_properties(${library} PROPERTIES INTERPROCEDURAL_OPTIMIZATION_Release ON)
    endif()
endfunction(configure_library)
