; Auto-generated. Do not edit!


(cl:in-package N_Robot-srv)


;//! \htmlinclude NMotionCtrl_JoyCmdMotion_srv-request.msg.html

(cl:defclass <NMotionCtrl_JoyCmdMotion_srv-request> (roslisp-msg-protocol:ros-message)
  ((s16JoyX
    :reader s16JoyX
    :initarg :s16JoyX
    :type cl:fixnum
    :initform 0)
   (s16JoyY
    :reader s16JoyY
    :initarg :s16JoyY
    :type cl:fixnum
    :initform 0)
   (s16JoyZ
    :reader s16JoyZ
    :initarg :s16JoyZ
    :type cl:fixnum
    :initform 0))
)

(cl:defclass NMotionCtrl_JoyCmdMotion_srv-request (<NMotionCtrl_JoyCmdMotion_srv-request>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <NMotionCtrl_JoyCmdMotion_srv-request>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'NMotionCtrl_JoyCmdMotion_srv-request)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name N_Robot-srv:<NMotionCtrl_JoyCmdMotion_srv-request> is deprecated: use N_Robot-srv:NMotionCtrl_JoyCmdMotion_srv-request instead.")))

(cl:ensure-generic-function 's16JoyX-val :lambda-list '(m))
(cl:defmethod s16JoyX-val ((m <NMotionCtrl_JoyCmdMotion_srv-request>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader N_Robot-srv:s16JoyX-val is deprecated.  Use N_Robot-srv:s16JoyX instead.")
  (s16JoyX m))

(cl:ensure-generic-function 's16JoyY-val :lambda-list '(m))
(cl:defmethod s16JoyY-val ((m <NMotionCtrl_JoyCmdMotion_srv-request>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader N_Robot-srv:s16JoyY-val is deprecated.  Use N_Robot-srv:s16JoyY instead.")
  (s16JoyY m))

(cl:ensure-generic-function 's16JoyZ-val :lambda-list '(m))
(cl:defmethod s16JoyZ-val ((m <NMotionCtrl_JoyCmdMotion_srv-request>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader N_Robot-srv:s16JoyZ-val is deprecated.  Use N_Robot-srv:s16JoyZ instead.")
  (s16JoyZ m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <NMotionCtrl_JoyCmdMotion_srv-request>) ostream)
  "Serializes a message object of type '<NMotionCtrl_JoyCmdMotion_srv-request>"
  (cl:let* ((signed (cl:slot-value msg 's16JoyX)) (unsigned (cl:if (cl:< signed 0) (cl:+ signed 65536) signed)))
    (cl:write-byte (cl:ldb (cl:byte 8 0) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) unsigned) ostream)
    )
  (cl:let* ((signed (cl:slot-value msg 's16JoyY)) (unsigned (cl:if (cl:< signed 0) (cl:+ signed 65536) signed)))
    (cl:write-byte (cl:ldb (cl:byte 8 0) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) unsigned) ostream)
    )
  (cl:let* ((signed (cl:slot-value msg 's16JoyZ)) (unsigned (cl:if (cl:< signed 0) (cl:+ signed 65536) signed)))
    (cl:write-byte (cl:ldb (cl:byte 8 0) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) unsigned) ostream)
    )
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <NMotionCtrl_JoyCmdMotion_srv-request>) istream)
  "Deserializes a message object of type '<NMotionCtrl_JoyCmdMotion_srv-request>"
    (cl:let ((unsigned 0))
      (cl:setf (cl:ldb (cl:byte 8 0) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) unsigned) (cl:read-byte istream))
      (cl:setf (cl:slot-value msg 's16JoyX) (cl:if (cl:< unsigned 32768) unsigned (cl:- unsigned 65536))))
    (cl:let ((unsigned 0))
      (cl:setf (cl:ldb (cl:byte 8 0) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) unsigned) (cl:read-byte istream))
      (cl:setf (cl:slot-value msg 's16JoyY) (cl:if (cl:< unsigned 32768) unsigned (cl:- unsigned 65536))))
    (cl:let ((unsigned 0))
      (cl:setf (cl:ldb (cl:byte 8 0) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) unsigned) (cl:read-byte istream))
      (cl:setf (cl:slot-value msg 's16JoyZ) (cl:if (cl:< unsigned 32768) unsigned (cl:- unsigned 65536))))
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<NMotionCtrl_JoyCmdMotion_srv-request>)))
  "Returns string type for a service object of type '<NMotionCtrl_JoyCmdMotion_srv-request>"
  "N_Robot/NMotionCtrl_JoyCmdMotion_srvRequest")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'NMotionCtrl_JoyCmdMotion_srv-request)))
  "Returns string type for a service object of type 'NMotionCtrl_JoyCmdMotion_srv-request"
  "N_Robot/NMotionCtrl_JoyCmdMotion_srvRequest")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<NMotionCtrl_JoyCmdMotion_srv-request>)))
  "Returns md5sum for a message object of type '<NMotionCtrl_JoyCmdMotion_srv-request>"
  "0fae833057af8a323ca1d5d7b1f7154c")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'NMotionCtrl_JoyCmdMotion_srv-request)))
  "Returns md5sum for a message object of type 'NMotionCtrl_JoyCmdMotion_srv-request"
  "0fae833057af8a323ca1d5d7b1f7154c")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<NMotionCtrl_JoyCmdMotion_srv-request>)))
  "Returns full string definition for message of type '<NMotionCtrl_JoyCmdMotion_srv-request>"
  (cl:format cl:nil "int16  s16JoyX~%int16  s16JoyY~%int16  s16JoyZ~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'NMotionCtrl_JoyCmdMotion_srv-request)))
  "Returns full string definition for message of type 'NMotionCtrl_JoyCmdMotion_srv-request"
  (cl:format cl:nil "int16  s16JoyX~%int16  s16JoyY~%int16  s16JoyZ~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <NMotionCtrl_JoyCmdMotion_srv-request>))
  (cl:+ 0
     2
     2
     2
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <NMotionCtrl_JoyCmdMotion_srv-request>))
  "Converts a ROS message object to a list"
  (cl:list 'NMotionCtrl_JoyCmdMotion_srv-request
    (cl:cons ':s16JoyX (s16JoyX msg))
    (cl:cons ':s16JoyY (s16JoyY msg))
    (cl:cons ':s16JoyZ (s16JoyZ msg))
))
;//! \htmlinclude NMotionCtrl_JoyCmdMotion_srv-response.msg.html

(cl:defclass <NMotionCtrl_JoyCmdMotion_srv-response> (roslisp-msg-protocol:ros-message)
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

(cl:defclass NMotionCtrl_JoyCmdMotion_srv-response (<NMotionCtrl_JoyCmdMotion_srv-response>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <NMotionCtrl_JoyCmdMotion_srv-response>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'NMotionCtrl_JoyCmdMotion_srv-response)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name N_Robot-srv:<NMotionCtrl_JoyCmdMotion_srv-response> is deprecated: use N_Robot-srv:NMotionCtrl_JoyCmdMotion_srv-response instead.")))

(cl:ensure-generic-function 's32ErrCode-val :lambda-list '(m))
(cl:defmethod s32ErrCode-val ((m <NMotionCtrl_JoyCmdMotion_srv-response>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader N_Robot-srv:s32ErrCode-val is deprecated.  Use N_Robot-srv:s32ErrCode instead.")
  (s32ErrCode m))

(cl:ensure-generic-function 'strErrInfo-val :lambda-list '(m))
(cl:defmethod strErrInfo-val ((m <NMotionCtrl_JoyCmdMotion_srv-response>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader N_Robot-srv:strErrInfo-val is deprecated.  Use N_Robot-srv:strErrInfo instead.")
  (strErrInfo m))

(cl:ensure-generic-function 'u8SysErrStatus-val :lambda-list '(m))
(cl:defmethod u8SysErrStatus-val ((m <NMotionCtrl_JoyCmdMotion_srv-response>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader N_Robot-srv:u8SysErrStatus-val is deprecated.  Use N_Robot-srv:u8SysErrStatus instead.")
  (u8SysErrStatus m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <NMotionCtrl_JoyCmdMotion_srv-response>) ostream)
  "Serializes a message object of type '<NMotionCtrl_JoyCmdMotion_srv-response>"
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
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <NMotionCtrl_JoyCmdMotion_srv-response>) istream)
  "Deserializes a message object of type '<NMotionCtrl_JoyCmdMotion_srv-response>"
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
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<NMotionCtrl_JoyCmdMotion_srv-response>)))
  "Returns string type for a service object of type '<NMotionCtrl_JoyCmdMotion_srv-response>"
  "N_Robot/NMotionCtrl_JoyCmdMotion_srvResponse")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'NMotionCtrl_JoyCmdMotion_srv-response)))
  "Returns string type for a service object of type 'NMotionCtrl_JoyCmdMotion_srv-response"
  "N_Robot/NMotionCtrl_JoyCmdMotion_srvResponse")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<NMotionCtrl_JoyCmdMotion_srv-response>)))
  "Returns md5sum for a message object of type '<NMotionCtrl_JoyCmdMotion_srv-response>"
  "0fae833057af8a323ca1d5d7b1f7154c")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'NMotionCtrl_JoyCmdMotion_srv-response)))
  "Returns md5sum for a message object of type 'NMotionCtrl_JoyCmdMotion_srv-response"
  "0fae833057af8a323ca1d5d7b1f7154c")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<NMotionCtrl_JoyCmdMotion_srv-response>)))
  "Returns full string definition for message of type '<NMotionCtrl_JoyCmdMotion_srv-response>"
  (cl:format cl:nil "int32  s32ErrCode~%string strErrInfo~%uint8  u8SysErrStatus~%~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'NMotionCtrl_JoyCmdMotion_srv-response)))
  "Returns full string definition for message of type 'NMotionCtrl_JoyCmdMotion_srv-response"
  (cl:format cl:nil "int32  s32ErrCode~%string strErrInfo~%uint8  u8SysErrStatus~%~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <NMotionCtrl_JoyCmdMotion_srv-response>))
  (cl:+ 0
     4
     4 (cl:length (cl:slot-value msg 'strErrInfo))
     1
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <NMotionCtrl_JoyCmdMotion_srv-response>))
  "Converts a ROS message object to a list"
  (cl:list 'NMotionCtrl_JoyCmdMotion_srv-response
    (cl:cons ':s32ErrCode (s32ErrCode msg))
    (cl:cons ':strErrInfo (strErrInfo msg))
    (cl:cons ':u8SysErrStatus (u8SysErrStatus msg))
))
(cl:defmethod roslisp-msg-protocol:service-request-type ((msg (cl:eql 'NMotionCtrl_JoyCmdMotion_srv)))
  'NMotionCtrl_JoyCmdMotion_srv-request)
(cl:defmethod roslisp-msg-protocol:service-response-type ((msg (cl:eql 'NMotionCtrl_JoyCmdMotion_srv)))
  'NMotionCtrl_JoyCmdMotion_srv-response)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'NMotionCtrl_JoyCmdMotion_srv)))
  "Returns string type for a service object of type '<NMotionCtrl_JoyCmdMotion_srv>"
  "N_Robot/NMotionCtrl_JoyCmdMotion_srv")