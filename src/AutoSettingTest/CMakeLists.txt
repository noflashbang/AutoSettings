

Include(FetchContent)

FetchContent_Declare(
  Catch2
  GIT_REPOSITORY https://github.com/catchorg/Catch2.git
  GIT_TAG        v3.4.0 # or a later release
)

FetchContent_MakeAvailable(Catch2)



cmake_path(GET CMAKE_CURRENT_SOURCE_DIR PARENT_PATH PARENT_DIR)

set( externHeaders 
    ${PARENT_DIR}/include/AutoSettings/AutoSettingApi.h
    ${PARENT_DIR}/include/AutoSettings/AutoSettingCore.h
)

set( testSource 
   ${CMAKE_CURRENT_SOURCE_DIR}/src/main.cpp
)

add_executable(AutoSettingTest ${testSource} ${externHeaders})
target_link_libraries(AutoSettingTest PRIVATE Catch2::Catch2WithMain)
target_link_libraries(AutoSettingTest PUBLIC AutoSettings)

add_dependencies(AutoSettingTest AutoSettings)

target_include_directories( AutoSettingTest	PUBLIC ${PARENT_DIR}/AutoSettings/include/AutoSettings )

target_sources( AutoSettingTest PRIVATE 
    ${testSource}
 )

 install(TARGETS AutoSettingTest
        RUNTIME           
          COMPONENT Runtime
          DESTINATION test
)
install(FILES $<TARGET_RUNTIME_DLLS:AutoSettingTest> DESTINATION test)