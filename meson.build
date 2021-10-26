project('LetiGame', 'cpp',
  version : '0.1',
  default_options : ['warning_level=3',
                     'cpp_std=c++14'])

target_name = 'letigame'
sources = ['src/main.cpp', 'src/game/game.cpp', 'src/scene/scene.cpp', 'src/cell/cell.cpp']
headers = include_directories('src')

executable(target_name, sources,
  include_directories : headers,
  install : true)

