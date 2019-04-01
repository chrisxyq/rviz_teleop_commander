FILE(REMOVE_RECURSE
  "../msg_gen"
  "../srv_gen"
  "../msg_gen"
  "../srv_gen"
  "../src/N_Robot/msg"
  "../src/N_Robot/srv"
  "CMakeFiles/ROSBUILD_genmsg_py"
  "../src/N_Robot/msg/__init__.py"
  "../src/N_Robot/msg/_PathFinder_msg.py"
  "../src/N_Robot/msg/_Localization_msg.py"
  "../src/N_Robot/msg/_CyberJoy_msg.py"
)

# Per-language clean rules from dependency scanning.
FOREACH(lang)
  INCLUDE(CMakeFiles/ROSBUILD_genmsg_py.dir/cmake_clean_${lang}.cmake OPTIONAL)
ENDFOREACH(lang)
