cmake_minimum_required(VERSION 3.14) # SFML требует минимум 3.14 для FetchContent
project(mario)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_POLICY_VERSION_MINIMUM 3.5)
file(COPY ${CMAKE_SOURCE_DIR}/images
        DESTINATION ${CMAKE_BINARY_DIR})
# --- 1. Настройка зависимостей ---
include(FetchContent)

# Скачиваем и собираем SFML
FetchContent_Declare(
        sfml
        GIT_REPOSITORY https://github.com/SFML/SFML.git
        GIT_TAG 2.5.1 # Указываем нужную версию
)
FetchContent_MakeAvailable(sfml)
# --- 2. Сборка вашего проекта ---
add_executable(mario main.cpp Hero.cpp Hero.h block.cpp block.h)

# --- 3. Подключение библиотек ---
# Так как мы использовали FetchContent, библиотеки называются просто sfml-*
target_link_libraries(mario PRIVATE sfml-network sfml-graphics sfml-window)

# --- 4. Автоматическое копирование DLL в папку с exe (только Windows) ---
if(WIN32)
    add_custom_command(TARGET mario POST_BUILD
            COMMAND ${CMAKE_COMMAND} -E copy_if_different
            "$<TARGET_RUNTIME_DLLS:mario>"
            $<TARGET_FILE_DIR:mario>
            COMMAND_EXPAND_LISTS
    )
endif()