project('LetiGame', 'cpp',
  version : '0.1',
  default_options : ['warning_level=3',
                     'cpp_std=c++14'])

target_name = 'letigame'
sources = ['src/main.cpp', 'src/game.cpp', 'src/scene.cpp', 'src/cell.cpp']
headers = include_directories('src/headers')

executable(target_name, sources,
  include_directories : headers,
  install : true)

