cmake_minimum_required(VERSION 3.13)
project(DoomNukem)

set(CMAKE_CXX_STANDARD 14)

set(CMAKE_CXX_FLAGS "-Wall -Wextra -Werror
					-march=native -m64 -Ofast -O2 -flto -funroll-loops" )

set(CMAKE_MODULE_PATH ${PROJECT_SOURCE_DIR}/CMake)

include_directories(engine/includes)
include_directories(engine/includes/SDL2)
include_directories(game/includes)
include_directories(editor/includes)
include_directories(lib/libft/includes)
include_directories(${SDL2_INCLUDE_DIR})
include_directories(${SDL2_MIXER_INCLUDE_DIR})
include_directories(${SDL2_TTF_INCLUDE_DIR})

find_package(SDL2 REQUIRED)
find_package(SDL2_mixer REQUIRED)
find_package(SDL2_ttf REQUIRED)

set(SDL_INCLUDES engine/includes/SDL2/)

set(GAME_INC game/includes/game.h)
set(GAME_SRC
		game/srcs/freefps.c
		game/srcs/weapon_fire.c
		game/srcs/game_controller_down.c
		game/srcs/game_controller_up.c
		game/srcs/game_movement.c
		game/srcs/game_movement_funs.c
		game/srcs/gravitation.c
		game/srcs/multi_threading.c)

set(ENG_INC engine/includes/engine.h)
set(ENG_SRC
		engine/srcs/bresenham.c
		engine/srcs/color.c
		engine/srcs/intersection_funs.c
		engine/srcs/intersection_funs_help.c
		engine/srcs/render_cycle.c
		engine/srcs/render_cycle2.c
		engine/srcs/render_wall.c
		engine/srcs/render_wall_help.c
		engine/srcs/render_world.c
		engine/srcs/render_main.c
		engine/srcs/render_particle.c
		engine/srcs/render_particle_2.c
		engine/srcs/sprite_render.c
		engine/srcs/texture_math.c
		engine/srcs/sprite_render_2.c
		engine/srcs/shoot_main.c
		engine/srcs/bresenham2.c
		engine/srcs/engine.c
		engine/srcs/error_handler.c
		engine/srcs/hud_draw.c
		engine/srcs/hud_draw1.c
		engine/srcs/images.c
		engine/srcs/normal.c
		engine/srcs/objects.c
		engine/srcs/parser.c
		engine/srcs/parser_errors.c
		engine/srcs/parser_filler.c
		engine/srcs/parser_reader.c
		engine/srcs/parser_utility.c
		engine/srcs/parser_texture.c
		engine/srcs/shoot.c
		engine/srcs/texture.c
		engine/srcs/utility.c
		engine/srcs/parser_weapon.c
		engine/srcs/parser_enemy.c
		engine/srcs/relative_coord.c
		engine/srcs/parser_items.c
		engine/srcs/parser_hud.c
		engine/srcs/sound.c
		engine/srcs/sprite_render.c
		engine/srcs/sprite_render_stack.c
		engine/srcs/sort.c
		engine/srcs/render_stack.c
		engine/srcs/checksum.c
		engine/srcs/pickup.c
		engine/srcs/font.c
		engine/srcs/parser_player.c
		engine/srcs/parser_items_2.c
		engine/srcs/sound_2.c
		engine/srcs/parser_point_3d.c
		engine/srcs/parser_sprite.c
		engine/srcs/parser_object.c
		engine/srcs/parser_polygone.c
		engine/srcs/parser_sector.c
		engine/srcs/parser_sprobject.c
		engine/srcs/parser_worldbox.c
		engine/srcs/parser_player_2.c
		engine/srcs/parser_world.c
		engine/srcs/parser_sector_2.c
		engine/srcs/parser_errors_2.c
		engine/srcs/parser_errors_3.c
		engine/srcs/parser_sprite_2.c
		engine/srcs/objects_help.c
		engine/srcs/render_wall2.c
		engine/srcs/shoot_help.c
		engine/srcs/parser_player_2.c
		engine/srcs/parser_color.c
		engine/srcs/parser_package.c
		engine/srcs/close.c
		engine/srcs/parser_filename.c)

set(EDITOR_INC editor/includes/editor.h)
set(EDITOR_SRC
		editor/srcs/checksum.c
		editor/srcs/checksum_errors.c)

add_executable(DoomNukem
				${GAME_INC} ${GAME_SRC}
				${ENG_INC} ${ENG_SRC}
				${SDL_DIRECTORY} ${SDL_INCLUDES})

#add_executable(DoomEditor
#			${ENG_INC} ${ENG_SRC}
#			${EDITOR_INC} ${EDITOR_SRC}
#			${SDL_DIRECTORY} ${SDL_INCLUDES})

add_subdirectory(lib/libft)

target_link_libraries(DoomNukem ${SDL2_LIBRARY} ${SDL2_MIXER_LIBRARY} ${SDL2_TTF_LIBRARY} libft)
#target_link_libraries(DoomEditor ${SDL2_LIBRARY} ${SDL2_MIXER_LIBRARY} ${SDL2_TTF_LIBRARY} libft)
