# This Python file uses the following encoding: utf-8
"""autogenerated by genpy from N_Robot/OFPS1_ReadEncoder_srvRequest.msg. Do not edit."""
import sys
python3 = True if sys.hexversion > 0x03000000 else False
import genpy
import struct


class OFPS1_ReadEncoder_srvRequest(genpy.Message):
  _md5sum = "d41d8cd98f00b204e9800998ecf8427e"
  _type = "N_Robot/OFPS1_ReadEncoder_srvRequest"
  _has_header = False #flag to mark the presence of a Header object
  _full_text = """"""
  __slots__ = []
  _slot_types = []

  def __init__(self, *args, **kwds):
    """
    Constructor. Any message fields that are implicitly/explicitly
    set to None will be assigned a default value. The recommend
    use is keyword arguments as this is more robust to future message
    changes.  You cannot mix in-order arguments and keyword arguments.

    The available fields are:
       

    :param args: complete set of field values, in .msg order
    :param kwds: use keyword arguments corresponding to message field names
    to set specific fields.
    """
    if args or kwds:
      super(OFPS1_ReadEncoder_srvRequest, self).__init__(*args, **kwds)

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
      pass
    except struct.error as se: self._check_types(struct.error("%s: '%s' when writing '%s'" % (type(se), str(se), str(locals().get('_x', self)))))
    except TypeError as te: self._check_types(ValueError("%s: '%s' when writing '%s'" % (type(te), str(te), str(locals().get('_x', self)))))

  def deserialize(self, str):
    """
    unpack serialized message in str into this message instance
    :param str: byte array of serialized message, ``str``
    """
    try:
      end = 0
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
      pass
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
      return self
    except struct.error as e:
      raise genpy.DeserializationError(e) #most likely buffer underfill

_struct_I = genpy.struct_I
# This Python file uses the following encoding: utf-8
"""autogenerated by genpy from N_Robot/OFPS1_ReadEncoder_srvResponse.msg. Do not edit."""
import sys
python3 = True if sys.hexversion > 0x03000000 else False
import genpy
import struct


class OFPS1_ReadEncoder_srvResponse(genpy.Message):
  _md5sum = "fde9ee8a9f7ccc3f22d8f39b640b16d0"
  _type = "N_Robot/OFPS1_ReadEncoder_srvResponse"
  _has_header = False #flag to mark the presence of a Header object
  _full_text = """int32  s32ErrCode
string strErrInfo
float32  f32Encoder1
float32  f32Encoder2
float32  f32Encoder3

"""
  __slots__ = ['s32ErrCode','strErrInfo','f32Encoder1','f32Encoder2','f32Encoder3']
  _slot_types = ['int32','string','float32','float32','float32']

  def __init__(self, *args, **kwds):
    """
    Constructor. Any message fields that are implicitly/explicitly
    set to None will be assigned a default value. The recommend
    use is keyword arguments as this is more robust to future message
    changes.  You cannot mix in-order arguments and keyword arguments.

    The available fields are:
       s32ErrCode,strErrInfo,f32Encoder1,f32Encoder2,f32Encoder3

    :param args: complete set of field values, in .msg order
    :param kwds: use keyword arguments corresponding to message field names
    to set specific fields.
    """
    if args or kwds:
      super(OFPS1_ReadEncoder_srvResponse, self).__init__(*args, **kwds)
      #message fields cannot be None, assign default values for those that are
      if self.s32ErrCode is None:
        self.s32ErrCode = 0
      if self.strErrInfo is None:
        self.strErrInfo = ''
      if self.f32Encoder1 is None:
        self.f32Encoder1 = 0.
      if self.f32Encoder2 is None:
        self.f32Encoder2 = 0.
      if self.f32Encoder3 is None:
        self.f32Encoder3 = 0.
    else:
      self.s32ErrCode = 0
      self.strErrInfo = ''
      self.f32Encoder1 = 0.
      self.f32Encoder2 = 0.
      self.f32Encoder3 = 0.

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
      _x = self
      buff.write(_struct_3f.pack(_x.f32Encoder1, _x.f32Encoder2, _x.f32Encoder3))
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
      _x = self
      start = end
      end += 12
      (_x.f32Encoder1, _x.f32Encoder2, _x.f32Encoder3,) = _struct_3f.unpack(str[start:end])
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
      _x = self
      buff.write(_struct_3f.pack(_x.f32Encoder1, _x.f32Encoder2, _x.f32Encoder3))
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
      _x = self
      start = end
      end += 12
      (_x.f32Encoder1, _x.f32Encoder2, _x.f32Encoder3,) = _struct_3f.unpack(str[start:end])
      return self
    except struct.error as e:
      raise genpy.DeserializationError(e) #most likely buffer underfill

_struct_I = genpy.struct_I
_struct_i = struct.Struct("<i")
_struct_3f = struct.Struct("<3f")
class OFPS1_ReadEncoder_srv(object):
  _type          = 'N_Robot/OFPS1_ReadEncoder_srv'
  _md5sum = 'fde9ee8a9f7ccc3f22d8f39b640b16d0'
  _request_class  = OFPS1_ReadEncoder_srvRequest
  _response_class = OFPS1_ReadEncoder_srvResponse
