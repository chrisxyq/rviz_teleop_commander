FILE(REMOVE_RECURSE
  "../msg_gen"
  "../srv_gen"
  "../msg_gen"
  "../srv_gen"
  "../src/N_Robot/msg"
  "../src/N_Robot/srv"
  "CMakeFiles/tests"
)

# Per-language clean rules from dependency scanning.
FOREACH(lang)
  INCLUDE(CMakeFiles/tests.dir/cmake_clean_${lang}.cmake OPTIONAL)
ENDFOREACH(lang)