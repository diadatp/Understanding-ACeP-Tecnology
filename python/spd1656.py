# This is a generated file! Please edit source .ksy file and use kaitai-struct-compiler to rebuild

from pkg_resources import parse_version
import kaitaistruct
from kaitaistruct import KaitaiStruct, KaitaiStream, BytesIO
from enum import Enum


if parse_version(kaitaistruct.__version__) < parse_version('0.9'):
    raise Exception("Incompatible Kaitai Struct Python API: 0.9 or later is required, but you have %s" % (kaitaistruct.__version__))

class Spd1656(KaitaiStruct):

    class LutcLvl(Enum):
        vcom_dc = 0
        vcomh = 1
        vcoml = 2
        hiz = 3

    class LutLvl(Enum):
        vss = 0
        vsh = 1
        vsl = 2
        vsh_lv = 3
        vsl_lv = 4
        vsl_lv2 = 5
        hiz = 7
    def __init__(self, _io, _parent=None, _root=None):
        self._io = _io
        self._parent = _parent
        self._root = _root if _root else self
        self._read()

    def _read(self):
        self.waveform_luts = [None] * (10)
        for i in range(10):
            self.waveform_luts[i] = Spd1656.LutT(self._io, self, self._root)

        self.vcom_luts = [None] * (10)
        for i in range(10):
            self.vcom_luts[i] = Spd1656.Lutc(self._io, self, self._root)

        self.xon_luts = [None] * (10)
        for i in range(10):
            self.xon_luts[i] = Spd1656.Lutxon(self._io, self, self._root)


    class LutT(KaitaiStruct):
        def __init__(self, _io, _parent=None, _root=None):
            self._io = _io
            self._parent = _parent
            self._root = _root if _root else self
            self._read()

        def _read(self):
            self.luts = [None] * (8)
            for i in range(8):
                self.luts[i] = Spd1656.Lut(self._io, self, self._root)



    class VsxcLvl(KaitaiStruct):
        def __init__(self, _io, _parent=None, _root=None):
            self._io = _io
            self._parent = _parent
            self._root = _root if _root else self
            self._read()

        def _read(self):
            self.vshc_lvl = self._io.read_u1()
            self.vslc_lvl = self._io.read_u1()


    class LutGroup(KaitaiStruct):
        def __init__(self, _io, _parent=None, _root=None):
            self._io = _io
            self._parent = _parent
            self._root = _root if _root else self
            self._read()

        def _read(self):
            self.rp = self._io.read_u1()
            self.lvl = [None] * (8)
            for i in range(8):
                self.lvl[i] = KaitaiStream.resolve_enum(Spd1656.LutLvl, self._io.read_bits_int_be(4))

            self._io.align_to_byte()
            self.tp = [None] * (8)
            for i in range(8):
                self.tp[i] = self._io.read_u1()



    class Lutc(KaitaiStruct):
        def __init__(self, _io, _parent=None, _root=None):
            self._io = _io
            self._parent = _parent
            self._root = _root if _root else self
            self._read()

        def _read(self):
            self.lut = [None] * (20)
            for i in range(20):
                self.lut[i] = Spd1656.LutcGroup(self._io, self, self._root)



    class Lutxon(KaitaiStruct):
        def __init__(self, _io, _parent=None, _root=None):
            self._io = _io
            self._parent = _parent
            self._root = _root if _root else self
            self._read()

        def _read(self):
            self.lut = [None] * (20)
            for i in range(20):
                self.lut[i] = Spd1656.LutxonGroup(self._io, self, self._root)



    class VslLvl2(KaitaiStruct):
        def __init__(self, _io, _parent=None, _root=None):
            self._io = _io
            self._parent = _parent
            self._root = _root if _root else self
            self._read()

        def _read(self):
            self.en = self._io.read_bits_int_be(1) != 0
            self.dummy = self._io.read_bits_int_be(1) != 0
            self.vslc_lvl2 = self._io.read_bits_int_be(6)


    class LutxonGroup(KaitaiStruct):
        def __init__(self, _io, _parent=None, _root=None):
            self._io = _io
            self._parent = _parent
            self._root = _root if _root else self
            self._read()

        def _read(self):
            self.rp = self._io.read_u1()
            self.xon = [None] * (8)
            for i in range(8):
                self.xon[i] = self._io.read_bits_int_be(1) != 0

            self._io.align_to_byte()
            self.tp = [None] * (8)
            for i in range(8):
                self.tp[i] = self._io.read_u1()



    class LutcGroup(KaitaiStruct):
        def __init__(self, _io, _parent=None, _root=None):
            self._io = _io
            self._parent = _parent
            self._root = _root if _root else self
            self._read()

        def _read(self):
            self.rp = self._io.read_u1()
            self.lvl = [None] * (8)
            for i in range(8):
                self.lvl[i] = KaitaiStream.resolve_enum(Spd1656.LutcLvl, self._io.read_bits_int_be(2))

            self._io.align_to_byte()
            self.tp = [None] * (8)
            for i in range(8):
                self.tp[i] = self._io.read_u1()



    class Lut(KaitaiStruct):
        def __init__(self, _io, _parent=None, _root=None):
            self._io = _io
            self._parent = _parent
            self._root = _root if _root else self
            self._read()

        def _read(self):
            self.lut = [None] * (20)
            for i in range(20):
                self.lut[i] = Spd1656.LutGroup(self._io, self, self._root)



    @property
    def vcm_dc(self):
        if hasattr(self, '_m_vcm_dc'):
            return self._m_vcm_dc if hasattr(self, '_m_vcm_dc') else None

        _pos = self._io.pos()
        self._io.seek(25600)
        self._m_vcm_dc = self._io.read_u1()
        self._io.seek(_pos)
        return self._m_vcm_dc if hasattr(self, '_m_vcm_dc') else None

    @property
    def vcm_dc_in_volt(self):
        if hasattr(self, '_m_vcm_dc_in_volt'):
            return self._m_vcm_dc_in_volt if hasattr(self, '_m_vcm_dc_in_volt') else None

        self._m_vcm_dc_in_volt = (self.vcm_dc * -0.05)
        return self._m_vcm_dc_in_volt if hasattr(self, '_m_vcm_dc_in_volt') else None

    @property
    def vsl_lvl2_setting(self):
        if hasattr(self, '_m_vsl_lvl2_setting'):
            return self._m_vsl_lvl2_setting if hasattr(self, '_m_vsl_lvl2_setting') else None

        _pos = self._io.pos()
        self._io.seek(25031)
        self._m_vsl_lvl2_setting = [None] * (10)
        for i in range(10):
            self._m_vsl_lvl2_setting[i] = Spd1656.VslLvl2(self._io, self, self._root)

        self._io.seek(_pos)
        return self._m_vsl_lvl2_setting if hasattr(self, '_m_vsl_lvl2_setting') else None

    @property
    def framerate(self):
        if hasattr(self, '_m_framerate'):
            return self._m_framerate if hasattr(self, '_m_framerate') else None

        _pos = self._io.pos()
        self._io.seek(25616)
        self._m_framerate = [None] * (10)
        for i in range(10):
            self._m_framerate[i] = self._io.read_u1()

        self._io.seek(_pos)
        return self._m_framerate if hasattr(self, '_m_framerate') else None

    @property
    def temperature_boundary(self):
        if hasattr(self, '_m_temperature_boundary'):
            return self._m_temperature_boundary if hasattr(self, '_m_temperature_boundary') else None

        _pos = self._io.pos()
        self._io.seek(25002)
        self._m_temperature_boundary = [None] * (9)
        for i in range(9):
            self._m_temperature_boundary[i] = self._io.read_u1()

        self._io.seek(_pos)
        return self._m_temperature_boundary if hasattr(self, '_m_temperature_boundary') else None

    @property
    def vsx_lv_setting(self):
        if hasattr(self, '_m_vsx_lv_setting'):
            return self._m_vsx_lv_setting if hasattr(self, '_m_vsx_lv_setting') else None

        _pos = self._io.pos()
        self._io.seek(25011)
        self._m_vsx_lv_setting = [None] * (10)
        for i in range(10):
            self._m_vsx_lv_setting[i] = Spd1656.VsxcLvl(self._io, self, self._root)

        self._io.seek(_pos)
        return self._m_vsx_lv_setting if hasattr(self, '_m_vsx_lv_setting') else None



