# will be implictly used for any compilation unit if not overrided by SYSTEM_INCLUDE_FOLDERS parameter
# these directories go as -isystem <dir> to avoid warnings from code of third-party libraries

file(COPY ${CMAKE_CURRENT_SOURCE_DIR}/mtpio.bios/ DESTINATION ${CMAKE_CURRENT_BINARY_DIR}/mtpio.bios/)
file(COPY ${CMAKE_CURRENT_SOURCE_DIR}/mtpio.msig/ DESTINATION ${CMAKE_CURRENT_BINARY_DIR}/mtpio.msig/)
file(COPY ${CMAKE_CURRENT_SOURCE_DIR}/mtpio.system/ DESTINATION ${CMAKE_CURRENT_BINARY_DIR}/mtpio.system/)
file(COPY ${CMAKE_CURRENT_SOURCE_DIR}/mtpio.token/ DESTINATION ${CMAKE_CURRENT_BINARY_DIR}/mtpio.token/)
file(COPY ${CMAKE_CURRENT_SOURCE_DIR}/mtpio.wrap/ DESTINATION ${CMAKE_CURRENT_BINARY_DIR}/mtpio.wrap/)

file(COPY ${CMAKE_CURRENT_SOURCE_DIR}/old_versions/v1.6.0-rc3/mtpio.bios/ DESTINATION ${CMAKE_CURRENT_BINARY_DIR}/old_versions/v1.6.0-rc3/mtpio.bios/)
file(COPY ${CMAKE_CURRENT_SOURCE_DIR}/old_versions/v1.7.0-develop-preactivate_feature/mtpio.bios/ DESTINATION ${CMAKE_CURRENT_BINARY_DIR}/old_versions/v1.7.0-develop-preactivate_feature/mtpio.bios/)
