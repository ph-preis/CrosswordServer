project('crosswords', 'cpp')

cc = meson.get_compiler('cpp')

depRestbed = declare_dependency(
  dependencies : cc.find_library('restbed', dirs : [meson.current_source_dir()]),
  include_directories : include_directories('.'),
)


incdir = include_directories('openapi/server/api', 'openapi/server/model', 'gtk', 'server')

gtkdep = [dependency('gtk+-3.0'), depRestbed, dependency('boost'), dependency('threads')]

src = ['main.cpp',
 'openapi/server/api/DefaultApi.cpp',
  'openapi/server/model/Cell.cpp',
   'openapi/server/model/CellLetter.cpp',
   'openapi/server/model/CellLetter_allOf.cpp',
   'openapi/server/model/CellQuestions.cpp',
   'openapi/server/model/CellQuestions_allOf.cpp',
   'openapi/server/model/Crossword.cpp',
   'openapi/server/model/Crossword_content_inner_inner.cpp',
   'openapi/server/model/Question.cpp']


executable('demo', src, dependencies : gtkdep, include_directories : incdir)
