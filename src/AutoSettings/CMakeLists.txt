
add_compile_definitions(AUTOSET_EXPORTS)

set( externHeaders 
    ${CMAKE_CURRENT_SOURCE_DIR}/include/AutoSettings/AutoSettingApi.h
    ${CMAKE_CURRENT_SOURCE_DIR}/include/AutoSettings/AutoSettingCore.h
)

set( libHeaders 
    ${CMAKE_CURRENT_SOURCE_DIR}/src/AutoSetting.h
    ${CMAKE_CURRENT_SOURCE_DIR}/src/AutoSettingAdapter.h
    ${CMAKE_CURRENT_SOURCE_DIR}/src/AutoSettingEntry.h
    ${CMAKE_CURRENT_SOURCE_DIR}/src/AutoSettingGroup.h
    ${CMAKE_CURRENT_SOURCE_DIR}/src/AutoSettingSerializerIn.h
    ${CMAKE_CURRENT_SOURCE_DIR}/src/AutoSettingSerializerOut.h
    ${CMAKE_CURRENT_SOURCE_DIR}/src/Dator.h
    ${CMAKE_CURRENT_SOURCE_DIR}/src/IDator.h
    ${CMAKE_CURRENT_SOURCE_DIR}/src/ISerial.h
    ${CMAKE_CURRENT_SOURCE_DIR}/src/SerialBase.h
    ${CMAKE_CURRENT_SOURCE_DIR}/src/SerialIn.h
    ${CMAKE_CURRENT_SOURCE_DIR}/src/SerialOut.h
    ${CMAKE_CURRENT_SOURCE_DIR}/src/StandardLib.h
    ${CMAKE_CURRENT_SOURCE_DIR}/src/Util.h
)

set( libSource
    ${CMAKE_CURRENT_SOURCE_DIR}/src/AutoSetting.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/src/AutoSettingAdapter.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/src/AutoSettingApi.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/src/AutoSettingEntry.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/src/AutoSettingGroup.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/src/AutoSettingSerializerIn.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/src/AutoSettingSerializerOut.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/src/SerialBase.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/src/SerialIn.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/src/SerialOut.cpp
)

add_library (AutoSettings SHARED ${libSource} ${libHeaders} ${externHeaders}) 
target_include_directories( AutoSettings PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include/AutoSettings )
target_include_directories( AutoSettings PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/src )

target_sources( AutoSettings PRIVATE ${libSource} ${libHeaders} )

target_sources( AutoSettings PUBLIC FILE_SET HEADERS BASE_DIRS ${CMAKE_CURRENT_SOURCE_DIR}/include/AutoSettings FILES ${externHeaders} )

install(TARGETS AutoSettings
        RUNTIME DESTINATION bin          
        LIBRARY DESTINATION lib
        ARCHIVE DESTINATION lib
        FILE_SET HEADERS COMPONENT Development
)
