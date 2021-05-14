meta:
  id: spd1656
seq:
  - id: waveform_luts
    type: lut_t
    repeat: expr
    repeat-expr: 10
  - id: vcom_luts
    type: lutc
    repeat: expr
    repeat-expr: 10
  - id: xon_luts
    type: lutxon
    repeat: expr
    repeat-expr: 10
instances:
  temperature_boundary:
    pos: 25002
    type: u1
    repeat: expr
    repeat-expr: 9
  vsx_lv_setting:
    pos: 25011
    type: vsxc_lvl
    repeat: expr
    repeat-expr: 10
  vsl_lvl2_setting:
    pos: 25031
    type: vsl_lvl2
    repeat: expr
    repeat-expr: 10
  vcm_dc:
    pos: 25600
    type: u1
  vcm_dc_in_volt:
    value: vcm_dc * -0.05
  framerate:
    pos: 25616
    type: u1
    repeat: expr
    repeat-expr: 10
types:
  lut_t:
    seq:
      - id: luts
        type: lut
        repeat: expr
        repeat-expr: 8
  lut:
    seq:
      - id: lut
        type: lut_group
        repeat: expr
        repeat-expr: 20
  lut_group:
    seq:
      - id: rp
        type: u1
      - id: lvl
        type: b4
        enum: lut_lvl
        repeat: expr
        repeat-expr: 8
      - id: tp
        type: u1
        repeat: expr
        repeat-expr: 8
  lutc:
    seq:
      - id: lut
        type: lutc_group
        repeat: expr
        repeat-expr: 20
  lutc_group:
    seq:
      - id: rp
        type: u1
      - id: lvl
        type: b2
        enum: lutc_lvl
        repeat: expr
        repeat-expr: 8
      - id: tp
        type: u1
        repeat: expr
        repeat-expr: 8
  lutxon:
    seq:
      - id: lut
        type: lutxon_group
        repeat: expr
        repeat-expr: 20
  lutxon_group:
    seq:
      - id: rp
        type: u1
      - id: xon
        type: b1
        repeat: expr
        repeat-expr: 8
      - id: tp
        type: u1
        repeat: expr
        repeat-expr: 8
  vsxc_lvl:
    seq:
      - id: vshc_lvl
        type: u1
      - id: vslc_lvl
        type: u1
  vsl_lvl2:
    seq:
      - id: en
        type: b1
      - id: dummy
        type: b1
      - id: vslc_lvl2
        type: b6
enums:
  lutc_lvl:
    0: vcom_dc
    1: vcomh
    2: vcoml
    3: hiz
  lut_lvl:
    0: vss
    1: vsh
    2: vsl
    3: vsh_lv
    4: vsl_lv
    5: vsl_lv2
    7: hiz

