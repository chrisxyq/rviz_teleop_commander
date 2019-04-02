# This Python file uses the following encoding: utf-8
"""autogenerated by genpy from N_Robot/OFPS1_SetPosition_srvRequest.msg. Do not edit."""
import sys
python3 = True if sys.hexversion > 0x03000000 else False
import genpy
import struct


class OFPS1_SetPosition_srvRequest(genpy.Message):
  _md5sum = "e1923dc8355807f063a816117325f206"
  _type = "N_Robot/OFPS1_SetPosition_srvRequest"
  _has_header = False #flag to mark the presence of a Header object
  _full_text = """float32  f32PositionX
float32  f32PositionY
float32  f32PositionTh
"""
  __slots__ = ['f32PositionX','f32PositionY','f32PositionTh']
  _slot_types = ['float32','float32','float32']

  def __init__(self, *args, **kwds):
    """
    Constructor. Any message fields that are implicitly/explicitly
    set to None will be assigned a default value. The recommend
    use is keyword arguments as this is more robust to future message
    changes.  You cannot mix in-order arguments and keyword arguments.

    The available fields are:
       f32PositionX,f32PositionY,f32PositionTh

    :param args: complete set of field values, in .msg order
    :param kwds: use keyword arguments corresponding to message field names
    to set specific fields.
    """
    if args or kwds:
      super(OFPS1_SetPosition_srvRequest, self).__init__(*args, **kwds)
      #message fields cannot be None, assign default values for those that are
      if self.f32PositionX is None:
        self.f32PositionX = 0.
      if self.f32PositionY is None:
        self.f32PositionY = 0.
      if self.f32PositionTh is None:
        self.f32PositionTh = 0.
    else:
      self.f32PositionX = 0.
      self.f32PositionY = 0.
      self.f32PositionTh = 0.

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
      buff.write(_struct_3f.pack(_x.f32PositionX, _x.f32PositionY, _x.f32PositionTh))
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
      end += 12
      (_x.f32PositionX, _x.f32PositionY, _x.f32PositionTh,) = _struct_3f.unpack(str[start:end])
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
      buff.write(_struct_3f.pack(_x.f32PositionX, _x.f32PositionY, _x.f32PositionTh))
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
      end += 12
      (_x.f32PositionX, _x.f32PositionY, _x.f32PositionTh,) = _struct_3f.unpack(str[start:end])
      return self
    except struct.error as e:
      raise genpy.DeserializationError(e) #most likely buffer underfill

_struct_I = genpy.struct_I
_struct_3f = struct.Struct("<3f")
# This Python file uses the following encoding: utf-8
"""autogenerated by genpy from N_Robot/OFPS1_SetPosition_srvResponse.msg. Do not edit."""
import sys
python3 = True if sys.hexversion > 0x03000000 else False
import genpy
import struct


class OFPS1_SetPosition_srvResponse(genpy.Message):
  _md5sum = "2cbb63f69963641e39b44412655d5578"
  _type = "N_Robot/OFPS1_SetPosition_srvResponse"
  _has_header = False #flag to mark the presence of a Header object
  _full_text = """int32  s32ErrCode
string strErrInfo


"""
  __slots__ = ['s32ErrCode','strErrInfo']
  _slot_types = ['int32','string']

  def __init__(self, *args, **kwds):
    """
    Constructor. Any message fields that are implicitly/explicitly
    set to None will be assigned a default value. The recommend
    use is keyword arguments as this is more robust to future message
    changes.  You cannot mix in-order arguments and keyword arguments.

    The available fields are:
       s32ErrCode,strErrInfo

    :param args: complete set of field values, in .msg order
    :param kwds: use keyword arguments corresponding to message field names
    to set specific fields.
    """
    if args or kwds:
      super(OFPS1_SetPosition_srvResponse, self).__init__(*args, **kwds)
      #message fields cannot be None, assign default values for those that are
      if self.s32ErrCode is None:
        self.s32ErrCode = 0
      if self.strErrInfo is None:
        self.strErrInfo = ''
    else:
      self.s32ErrCode = 0
      self.strErrInfo = ''

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
      buff.write(_struct_i.pack(self.s32ErrCode))
      _x = self.strErrInfo
      length = len(_x)
      if python3 or type(_x) == unicode:
        _x = _x.encode('utf-8')
        length = len(_x)
      if python3:
        buff.write(struct.pack('<I%sB'%length, length, *_x))
      else:
        buff.write(struct.pack('<I%ss'%length, length, _x))
    except struct.error as se: self._check_types(struct.error("%s: '%s' when writing '%s'" % (type(se), str(se), str(locals().get('_x', self)))))
    except TypeError as te: self._check_types(ValueError("%s: '%s' when writing '%s'" % (type(te), str(te), str(locals().get('_x', self)))))

  def deserialize(self, str):
    """
    unpack serialized message in str into this message instance
    :param str: byte array of serialized message, ``str``
    """
    try:
      end = 0
      start = end
      end += 4
      (self.s32ErrCode,) = _struct_i.unpack(str[start:end])
      start = end
      end += 4
      (length,) = _struct_I.unpack(str[start:end])
      start = end
      end += length
      if python3:
        self.strErrInfo = str[start:end].decode('utf-8')
      else:
        self.strErrInfo = str[start:end]
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
      buff.write(_struct_i.pack(self.s32ErrCode))
      _x = self.strErrInfo
      length = len(_x)
      if python3 or type(_x) == unicode:
        _x = _x.encode('utf-8')
        length = len(_x)
      if python3:
        buff.write(struct.pack('<I%sB'%length, length, *_x))
      else:
        buff.write(struct.pack('<I%ss'%length, length, _x))
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
      start = end
      end += 4
      (self.s32ErrCode,) = _struct_i.unpack(str[start:end])
      start = end
      end += 4
      (length,) = _struct_I.unpack(str[start:end])
      start = end
      end += length
      if python3:
        self.strErrInfo = str[start:end].decode('utf-8')
      else:
        self.strErrInfo = str[start:end]
      return self
    except struct.error as e:
      raise genpy.DeserializationError(e) #most likely buffer underfill

_struct_I = genpy.struct_I
_struct_i = struct.Struct("<i")
class OFPS1_SetPosition_srv(object):
  _type          = 'N_Robot/OFPS1_SetPosition_srv'
  _md5sum = '6ca74b599d4416d50467dc8670b61405'
  _request_class  = OFPS1_SetPosition_srvRequest
  _response_class = OFPS1_SetPosition_srvResponse