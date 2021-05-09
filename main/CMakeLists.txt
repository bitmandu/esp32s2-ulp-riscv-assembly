# CMakeLists.txt

idf_component_register(SRCS "esp32s2-ulp-riscv-assembly.c"
  INCLUDE_DIRS "."
  PRIV_REQUIRES ulp riscv)

set(ulp_app_name ulp_${COMPONENT_NAME})
set(ulp_riscv_sources "ulp/add.S" "ulp/main.c")
set(ulp_exp_dep_srcs "esp32s2-ulp-riscv-assembly.c")

ulp_embed_binary(${ulp_app_name} "${ulp_riscv_sources}" "${ulp_exp_dep_srcs}")
