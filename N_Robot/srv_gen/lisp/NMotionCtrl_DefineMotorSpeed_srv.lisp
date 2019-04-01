; Auto-generated. Do not edit!


(cl:in-package N_Robot-srv)


;//! \htmlinclude NMotionCtrl_DefineMotorSpeed_srv-request.msg.html

(cl:defclass <NMotionCtrl_DefineMotorSpeed_srv-request> (roslisp-msg-protocol:ros-message)
  ((s16Wheel1
    :reader s16Wheel1
    :initarg :s16Wheel1
    :type cl:fixnum
    :initform 0)
   (s16Wheel2
    :reader s16Wheel2
    :initarg :s16Wheel2
    :type cl:fixnum
    :initform 0)
   (s16Wheel3
    :reader s16Wheel3
    :initarg :s16Wheel3
    :type cl:fixnum
    :initform 0)
   (s16Wheel4
    :reader s16Wheel4
    :initarg :s16Wheel4
    :type cl:fixnum
    :initform 0))
)

(cl:defclass NMotionCtrl_DefineMotorSpeed_srv-request (<NMotionCtrl_DefineMotorSpeed_srv-request>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <NMotionCtrl_DefineMotorSpeed_srv-request>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'NMotionCtrl_DefineMotorSpeed_srv-request)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name N_Robot-srv:<NMotionCtrl_DefineMotorSpeed_srv-request> is deprecated: use N_Robot-srv:NMotionCtrl_DefineMotorSpeed_srv-request instead.")))

(cl:ensure-generic-function 's16Wheel1-val :lambda-list '(m))
(cl:defmethod s16Wheel1-val ((m <NMotionCtrl_DefineMotorSpeed_srv-request>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader N_Robot-srv:s16Wheel1-val is deprecated.  Use N_Robot-srv:s16Wheel1 instead.")
  (s16Wheel1 m))

(cl:ensure-generic-function 's16Wheel2-val :lambda-list '(m))
(cl:defmethod s16Wheel2-val ((m <NMotionCtrl_DefineMotorSpeed_srv-request>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader N_Robot-srv:s16Wheel2-val is deprecated.  Use N_Robot-srv:s16Wheel2 instead.")
  (s16Wheel2 m))

(cl:ensure-generic-function 's16Wheel3-val :lambda-list '(m))
(cl:defmethod s16Wheel3-val ((m <NMotionCtrl_DefineMotorSpeed_srv-request>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader N_Robot-srv:s16Wheel3-val is deprecated.  Use N_Robot-srv:s16Wheel3 instead.")
  (s16Wheel3 m))

(cl:ensure-generic-function 's16Wheel4-val :lambda-list '(m))
(cl:defmethod s16Wheel4-val ((m <NMotionCtrl_DefineMotorSpeed_srv-request>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader N_Robot-srv:s16Wheel4-val is deprecated.  Use N_Robot-srv:s16Wheel4 instead.")
  (s16Wheel4 m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <NMotionCtrl_DefineMotorSpeed_srv-request>) ostream)
  "Serializes a message object of type '<NMotionCtrl_DefineMotorSpeed_srv-request>"
  (cl:let* ((signed (cl:slot-value msg 's16Wheel1)) (unsigned (cl:if (cl:< signed 0) (cl:+ signed 65536) signed)))
    (cl:write-byte (cl:ldb (cl:byte 8 0) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) unsigned) ostream)
    )
  (cl:let* ((signed (cl:slot-value msg 's16Wheel2)) (unsigned (cl:if (cl:< signed 0) (cl:+ signed 65536) signed)))
    (cl:write-byte (cl:ldb (cl:byte 8 0) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) unsigned) ostream)
    )
  (cl:let* ((signed (cl:slot-value msg 's16Wheel3)) (unsigned (cl:if (cl:< signed 0) (cl:+ signed 65536) signed)))
    (cl:write-byte (cl:ldb (cl:byte 8 0) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) unsigned) ostream)
    )
  (cl:let* ((signed (cl:slot-value msg 's16Wheel4)) (unsigned (cl:if (cl:< signed 0) (cl:+ signed 65536) signed)))
    (cl:write-byte (cl:ldb (cl:byte 8 0) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) unsigned) ostream)
    )
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <NMotionCtrl_DefineMotorSpeed_srv-request>) istream)
  "Deserializes a message object of type '<NMotionCtrl_DefineMotorSpeed_srv-request>"
    (cl:let ((unsigned 0))
      (cl:setf (cl:ldb (cl:byte 8 0) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) unsigned) (cl:read-byte istream))
      (cl:setf (cl:slot-value msg 's16Wheel1) (cl:if (cl:< unsigned 32768) unsigned (cl:- unsigned 65536))))
    (cl:let ((unsigned 0))
      (cl:setf (cl:ldb (cl:byte 8 0) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) unsigned) (cl:read-byte istream))
      (cl:setf (cl:slot-value msg 's16Wheel2) (cl:if (cl:< unsigned 32768) unsigned (cl:- unsigned 65536))))
    (cl:let ((unsigned 0))
      (cl:setf (cl:ldb (cl:byte 8 0) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) unsigned) (cl:read-byte istream))
      (cl:setf (cl:slot-value msg 's16Wheel3) (cl:if (cl:< unsigned 32768) unsigned (cl:- unsigned 65536))))
    (cl:let ((unsigned 0))
      (cl:setf (cl:ldb (cl:byte 8 0) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) unsigned) (cl:read-byte istream))
      (cl:setf (cl:slot-value msg 's16Wheel4) (cl:if (cl:< unsigned 32768) unsigned (cl:- unsigned 65536))))
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<NMotionCtrl_DefineMotorSpeed_srv-request>)))
  "Returns string type for a service object of type '<NMotionCtrl_DefineMotorSpeed_srv-request>"
  "N_Robot/NMotionCtrl_DefineMotorSpeed_srvRequest")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'NMotionCtrl_DefineMotorSpeed_srv-request)))
  "Returns string type for a service object of type 'NMotionCtrl_DefineMotorSpeed_srv-request"
  "N_Robot/NMotionCtrl_DefineMotorSpeed_srvRequest")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<NMotionCtrl_DefineMotorSpeed_srv-request>)))
  "Returns md5sum for a message object of type '<NMotionCtrl_DefineMotorSpeed_srv-request>"
  "fec7131151353ec6f11a663d8091d4a1")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'NMotionCtrl_DefineMotorSpeed_srv-request)))
  "Returns md5sum for a message object of type 'NMotionCtrl_DefineMotorSpeed_srv-request"
  "fec7131151353ec6f11a663d8091d4a1")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<NMotionCtrl_DefineMotorSpeed_srv-request>)))
  "Returns full string definition for message of type '<NMotionCtrl_DefineMotorSpeed_srv-request>"
  (cl:format cl:nil "int16  s16Wheel1~%int16  s16Wheel2~%int16  s16Wheel3~%int16  s16Wheel4~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'NMotionCtrl_DefineMotorSpeed_srv-request)))
  "Returns full string definition for message of type 'NMotionCtrl_DefineMotorSpeed_srv-request"
  (cl:format cl:nil "int16  s16Wheel1~%int16  s16Wheel2~%int16  s16Wheel3~%int16  s16Wheel4~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <NMotionCtrl_DefineMotorSpeed_srv-request>))
  (cl:+ 0
     2
     2
     2
     2
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <NMotionCtrl_DefineMotorSpeed_srv-request>))
  "Converts a ROS message object to a list"
  (cl:list 'NMotionCtrl_DefineMotorSpeed_srv-request
    (cl:cons ':s16Wheel1 (s16Wheel1 msg))
    (cl:cons ':s16Wheel2 (s16Wheel2 msg))
    (cl:cons ':s16Wheel3 (s16Wheel3 msg))
    (cl:cons ':s16Wheel4 (s16Wheel4 msg))
))
;//! \htmlinclude NMotionCtrl_DefineMotorSpeed_srv-response.msg.html

(cl:defclass <NMotionCtrl_DefineMotorSpeed_srv-response> (roslisp-msg-protocol:ros-message)
  ((s32ErrCode
    :reader s32ErrCode
    :initarg :s32ErrCode
    :type cl:integer
    :initform 0)
   (strErrInfo
    :reader strErrInfo
    :initarg :strErrInfo
    :type cl:string
    :initform "")
   (u8SysErrStatus
    :reader u8SysErrStatus
    :initarg :u8SysErrStatus
    :type cl:fixnum
    :initform 0))
)

(cl:defclass NMotionCtrl_DefineMotorSpeed_srv-response (<NMotionCtrl_DefineMotorSpeed_srv-response>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <NMotionCtrl_DefineMotorSpeed_srv-response>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'NMotionCtrl_DefineMotorSpeed_srv-response)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name N_Robot-srv:<NMotionCtrl_DefineMotorSpeed_srv-response> is deprecated: use N_Robot-srv:NMotionCtrl_DefineMotorSpeed_srv-response instead.")))

(cl:ensure-generic-function 's32ErrCode-val :lambda-list '(m))
(cl:defmethod s32ErrCode-val ((m <NMotionCtrl_DefineMotorSpeed_srv-response>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader N_Robot-srv:s32ErrCode-val is deprecated.  Use N_Robot-srv:s32ErrCode instead.")
  (s32ErrCode m))

(cl:ensure-generic-function 'strErrInfo-val :lambda-list '(m))
(cl:defmethod strErrInfo-val ((m <NMotionCtrl_DefineMotorSpeed_srv-response>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader N_Robot-srv:strErrInfo-val is deprecated.  Use N_Robot-srv:strErrInfo instead.")
  (strErrInfo m))

(cl:ensure-generic-function 'u8SysErrStatus-val :lambda-list '(m))
(cl:defmethod u8SysErrStatus-val ((m <NMotionCtrl_DefineMotorSpeed_srv-response>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader N_Robot-srv:u8SysErrStatus-val is deprecated.  Use N_Robot-srv:u8SysErrStatus instead.")
  (u8SysErrStatus m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <NMotionCtrl_DefineMotorSpeed_srv-response>) ostream)
  "Serializes a message object of type '<NMotionCtrl_DefineMotorSpeed_srv-response>"
  (cl:let* ((signed (cl:slot-value msg 's32ErrCode)) (unsigned (cl:if (cl:< signed 0) (cl:+ signed 4294967296) signed)))
    (cl:write-byte (cl:ldb (cl:byte 8 0) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) unsigned) ostream)
    )
  (cl:let ((__ros_str_len (cl:length (cl:slot-value msg 'strErrInfo))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) __ros_str_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) __ros_str_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) __ros_str_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) __ros_str_len) ostream))
  (cl:map cl:nil #'(cl:lambda (c) (cl:write-byte (cl:char-code c) ostream)) (cl:slot-value msg 'strErrInfo))
  (cl:write-byte (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'u8SysErrStatus)) ostream)
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <NMotionCtrl_DefineMotorSpeed_srv-response>) istream)
  "Deserializes a message object of type '<NMotionCtrl_DefineMotorSpeed_srv-response>"
    (cl:let ((unsigned 0))
      (cl:setf (cl:ldb (cl:byte 8 0) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) unsigned) (cl:read-byte istream))
      (cl:setf (cl:slot-value msg 's32ErrCode) (cl:if (cl:< unsigned 2147483648) unsigned (cl:- unsigned 4294967296))))
    (cl:let ((__ros_str_len 0))
      (cl:setf (cl:ldb (cl:byte 8 0) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:slot-value msg 'strErrInfo) (cl:make-string __ros_str_len))
      (cl:dotimes (__ros_str_idx __ros_str_len msg)
        (cl:setf (cl:char (cl:slot-value msg 'strErrInfo) __ros_str_idx) (cl:code-char (cl:read-byte istream)))))
    (cl:setf (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'u8SysErrStatus)) (cl:read-byte istream))
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<NMotionCtrl_DefineMotorSpeed_srv-response>)))
  "Returns string type for a service object of type '<NMotionCtrl_DefineMotorSpeed_srv-response>"
  "N_Robot/NMotionCtrl_DefineMotorSpeed_srvResponse")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'NMotionCtrl_DefineMotorSpeed_srv-response)))
  "Returns string type for a service object of type 'NMotionCtrl_DefineMotorSpeed_srv-response"
  "N_Robot/NMotionCtrl_DefineMotorSpeed_srvResponse")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<NMotionCtrl_DefineMotorSpeed_srv-response>)))
  "Returns md5sum for a message object of type '<NMotionCtrl_DefineMotorSpeed_srv-response>"
  "fec7131151353ec6f11a663d8091d4a1")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'NMotionCtrl_DefineMotorSpeed_srv-response)))
  "Returns md5sum for a message object of type 'NMotionCtrl_DefineMotorSpeed_srv-response"
  "fec7131151353ec6f11a663d8091d4a1")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<NMotionCtrl_DefineMotorSpeed_srv-response>)))
  "Returns full string definition for message of type '<NMotionCtrl_DefineMotorSpeed_srv-response>"
  (cl:format cl:nil "int32  s32ErrCode~%string strErrInfo~%uint8  u8SysErrStatus~%~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'NMotionCtrl_DefineMotorSpeed_srv-response)))
  "Returns full string definition for message of type 'NMotionCtrl_DefineMotorSpeed_srv-response"
  (cl:format cl:nil "int32  s32ErrCode~%string strErrInfo~%uint8  u8SysErrStatus~%~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <NMotionCtrl_DefineMotorSpeed_srv-response>))
  (cl:+ 0
     4
     4 (cl:length (cl:slot-value msg 'strErrInfo))
     1
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <NMotionCtrl_DefineMotorSpeed_srv-response>))
  "Converts a ROS message object to a list"
  (cl:list 'NMotionCtrl_DefineMotorSpeed_srv-response
    (cl:cons ':s32ErrCode (s32ErrCode msg))
    (cl:cons ':strErrInfo (strErrInfo msg))
    (cl:cons ':u8SysErrStatus (u8SysErrStatus msg))
))
(cl:defmethod roslisp-msg-protocol:service-request-type ((msg (cl:eql 'NMotionCtrl_DefineMotorSpeed_srv)))
  'NMotionCtrl_DefineMotorSpeed_srv-request)
(cl:defmethod roslisp-msg-protocol:service-response-type ((msg (cl:eql 'NMotionCtrl_DefineMotorSpeed_srv)))
  'NMotionCtrl_DefineMotorSpeed_srv-response)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'NMotionCtrl_DefineMotorSpeed_srv)))
  "Returns string type for a service object of type '<NMotionCtrl_DefineMotorSpeed_srv>"
  "N_Robot/NMotionCtrl_DefineMotorSpeed_srv")