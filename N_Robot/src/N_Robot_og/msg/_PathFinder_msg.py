# This Python file uses the following encoding: utf-8
"""autogenerated by genpy from N_Robot/PathFinder_msg.msg. Do not edit."""
import sys
python3 = True if sys.hexversion > 0x03000000 else False
import genpy
import struct


class PathFinder_msg(genpy.Message):
  _md5sum = "a0b961ff8f78bdde7ce47c9a5aab32e2"
  _type = "N_Robot/PathFinder_msg"
  _has_header = False #flag to mark the presence of a Header object
  _full_text = """#Remote CTRLR VALID BIT
bool bValid
#JOY1
int16 i16JOY1X
int16 i16JOY1Y
int16 i16JOY1Z
#JOY2
int16 i16JOY2X
int16 i16JOY2Y
#JOY3
int16 i16JOY3X
int16 i16JOY3Y
#POT A/B
uint16 u16POTA
uint16 u16POTB
#BAND A/B
uint8 u8BAND
#ENC A/B
int8 i8ENCA
int8 i8ENCB
#TOG & BUTTON
uint16 u16Button

"""
  __slots__ = ['bValid','i16JOY1X','i16JOY1Y','i16JOY1Z','i16JOY2X','i16JOY2Y','i16JOY3X','i16JOY3Y','u16POTA','u16POTB','u8BAND','i8ENCA','i8ENCB','u16Button']
  _slot_types = ['bool','int16','int16','int16','int16','int16','int16','int16','uint16','uint16','uint8','int8','int8','uint16']

  def __init__(self, *args, **kwds):
    """
    Constructor. Any message fields that are implicitly/explicitly
    set to None will be assigned a default value. The recommend
    use is keyword arguments as this is more robust to future message
    changes.  You cannot mix in-order arguments and keyword arguments.

    The available fields are:
       bValid,i16JOY1X,i16JOY1Y,i16JOY1Z,i16JOY2X,i16JOY2Y,i16JOY3X,i16JOY3Y,u16POTA,u16POTB,u8BAND,i8ENCA,i8ENCB,u16Button

    :param args: complete set of field values, in .msg order
    :param kwds: use keyword arguments corresponding to message field names
    to set specific fields.
    """
    if args or kwds:
      super(PathFinder_msg, self).__init__(*args, **kwds)
      #message fields cannot be None, assign default values for those that are
      if self.bValid is None:
        self.bValid = False
      if self.i16JOY1X is None:
        self.i16JOY1X = 0
      if self.i16JOY1Y is None:
        self.i16JOY1Y = 0
      if self.i16JOY1Z is None:
        self.i16JOY1Z = 0
      if self.i16JOY2X is None:
        self.i16JOY2X = 0
      if self.i16JOY2Y is None:
        self.i16JOY2Y = 0
      if self.i16JOY3X is None:
        self.i16JOY3X = 0
      if self.i16JOY3Y is None:
        self.i16JOY3Y = 0
      if self.u16POTA is None:
        self.u16POTA = 0
      if self.u16POTB is None:
        self.u16POTB = 0
      if self.u8BAND is None:
        self.u8BAND = 0
      if self.i8ENCA is None:
        self.i8ENCA = 0
      if self.i8ENCB is None:
        self.i8ENCB = 0
      if self.u16Button is None:
        self.u16Button = 0
    else:
      self.bValid = False
      self.i16JOY1X = 0
      self.i16JOY1Y = 0
      self.i16JOY1Z = 0
      self.i16JOY2X = 0
      self.i16JOY2Y = 0
      self.i16JOY3X = 0
      self.i16JOY3Y = 0
      self.u16POTA = 0
      self.u16POTB = 0
      self.u8BAND = 0
      self.i8ENCA = 0
      self.i8ENCB = 0
      self.u16Button = 0

  def _get_types(self):
    """
    internal API method
    """
    return self._slot_types

  def serialize(self, buff):
    """
    serialize message into buffer
    :param buff: buffer, ``StringIO``
    """
    try:
      _x = self
      buff.write(_struct_B7h2HB2bH.pack(_x.bValid, _x.i16JOY1X, _x.i16JOY1Y, _x.i16JOY1Z, _x.i16JOY2X, _x.i16JOY2Y, _x.i16JOY3X, _x.i16JOY3Y, _x.u16POTA, _x.u16POTB, _x.u8BAND, _x.i8ENCA, _x.i8ENCB, _x.u16Button))
    except struct.error as se: self._check_types(struct.error("%s: '%s' when writing '%s'" % (type(se), str(se), str(locals().get('_x', self)))))
    except TypeError as te: self._check_types(ValueError("%s: '%s' when writing '%s'" % (type(te), str(te), str(locals().get('_x', self)))))

  def deserialize(self, str):
    """
    unpack serialized message in str into this message instance
    :param str: byte array of serialized message, ``str``
    """
    try:
      end = 0
      _x = self
      start = end
      end += 24
      (_x.bValid, _x.i16JOY1X, _x.i16JOY1Y, _x.i16JOY1Z, _x.i16JOY2X, _x.i16JOY2Y, _x.i16JOY3X, _x.i16JOY3Y, _x.u16POTA, _x.u16POTB, _x.u8BAND, _x.i8ENCA, _x.i8ENCB, _x.u16Button,) = _struct_B7h2HB2bH.unpack(str[start:end])
      self.bValid = bool(self.bValid)
      return self
    except struct.error as e:
      raise genpy.DeserializationError(e) #most likely buffer underfill


  def serialize_numpy(self, buff, numpy):
    """
    serialize message with numpy array types into buffer
    :param buff: buffer, ``StringIO``
    :param numpy: numpy python module
    """
    try:
      _x = self
      buff.write(_struct_B7h2HB2bH.pack(_x.bValid, _x.i16JOY1X, _x.i16JOY1Y, _x.i16JOY1Z, _x.i16JOY2X, _x.i16JOY2Y, _x.i16JOY3X, _x.i16JOY3Y, _x.u16POTA, _x.u16POTB, _x.u8BAND, _x.i8ENCA, _x.i8ENCB, _x.u16Button))
    except struct.error as se: self._check_types(struct.error("%s: '%s' when writing '%s'" % (type(se), str(se), str(locals().get('_x', self)))))
    except TypeError as te: self._check_types(ValueError("%s: '%s' when writing '%s'" % (type(te), str(te), str(locals().get('_x', self)))))

  def deserialize_numpy(self, str, numpy):
    """
    unpack serialized message in str into this message instance using numpy for array types
    :param str: byte array of serialized message, ``str``
    :param numpy: numpy python module
    """
    try:
      end = 0
      _x = self
      start = end
      end += 24
      (_x.bValid, _x.i16JOY1X, _x.i16JOY1Y, _x.i16JOY1Z, _x.i16JOY2X, _x.i16JOY2Y, _x.i16JOY3X, _x.i16JOY3Y, _x.u16POTA, _x.u16POTB, _x.u8BAND, _x.i8ENCA, _x.i8ENCB, _x.u16Button,) = _struct_B7h2HB2bH.unpack(str[start:end])
      self.bValid = bool(self.bValid)
      return self
    except struct.error as e:
      raise genpy.DeserializationError(e) #most likely buffer underfill

_struct_I = genpy.struct_I
_struct_B7h2HB2bH = struct.Struct("<B7h2HB2bH")