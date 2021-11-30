project('LetiGame', 'cpp',
  version : '0.1',
  default_options : ['warning_level=3',
                     'cpp_std=c++14'])

target_name = 'letigame'

sources = ['src/main.cpp',
  # Game classes
  'src/game/game.cpp',
  'src/scene/scene.cpp',
  'src/cell/cell.cpp',
  'src/gameObject/gameObject.cpp',
  # Unit hierarchy
  'src/unit/unit.cpp',
  'src/unit/infantry/swordsman.cpp',
  'src/unit/infantry/spearman.cpp',
  'src/unit/ranged/archer.cpp',
  'src/unit/ranged/crossbowman.cpp',
  'src/unit/cavalry/horseman.cpp',
  'src/unit/cavalry/knight.cpp',
  'src/unit/building/town.cpp',
]

headers = include_directories('src')

executable(target_name, sources,
  include_directories : headers,
  install : true)

