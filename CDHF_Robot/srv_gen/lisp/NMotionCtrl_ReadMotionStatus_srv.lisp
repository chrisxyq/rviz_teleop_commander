; Auto-generated. Do not edit!


(cl:in-package N_Robot-srv)


;//! \htmlinclude NMotionCtrl_ReadMotionStatus_srv-request.msg.html

(cl:defclass <NMotionCtrl_ReadMotionStatus_srv-request> (roslisp-msg-protocol:ros-message)
  ()
)

(cl:defclass NMotionCtrl_ReadMotionStatus_srv-request (<NMotionCtrl_ReadMotionStatus_srv-request>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <NMotionCtrl_ReadMotionStatus_srv-request>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'NMotionCtrl_ReadMotionStatus_srv-request)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name N_Robot-srv:<NMotionCtrl_ReadMotionStatus_srv-request> is deprecated: use N_Robot-srv:NMotionCtrl_ReadMotionStatus_srv-request instead.")))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <NMotionCtrl_ReadMotionStatus_srv-request>) ostream)
  "Serializes a message object of type '<NMotionCtrl_ReadMotionStatus_srv-request>"
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <NMotionCtrl_ReadMotionStatus_srv-request>) istream)
  "Deserializes a message object of type '<NMotionCtrl_ReadMotionStatus_srv-request>"
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<NMotionCtrl_ReadMotionStatus_srv-request>)))
  "Returns string type for a service object of type '<NMotionCtrl_ReadMotionStatus_srv-request>"
  "N_Robot/NMotionCtrl_ReadMotionStatus_srvRequest")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'NMotionCtrl_ReadMotionStatus_srv-request)))
  "Returns string type for a service object of type 'NMotionCtrl_ReadMotionStatus_srv-request"
  "N_Robot/NMotionCtrl_ReadMotionStatus_srvRequest")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<NMotionCtrl_ReadMotionStatus_srv-request>)))
  "Returns md5sum for a message object of type '<NMotionCtrl_ReadMotionStatus_srv-request>"
  "cab3d3372c649fc51ca4cd10570bd6c5")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'NMotionCtrl_ReadMotionStatus_srv-request)))
  "Returns md5sum for a message object of type 'NMotionCtrl_ReadMotionStatus_srv-request"
  "cab3d3372c649fc51ca4cd10570bd6c5")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<NMotionCtrl_ReadMotionStatus_srv-request>)))
  "Returns full string definition for message of type '<NMotionCtrl_ReadMotionStatus_srv-request>"
  (cl:format cl:nil "~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'NMotionCtrl_ReadMotionStatus_srv-request)))
  "Returns full string definition for message of type 'NMotionCtrl_ReadMotionStatus_srv-request"
  (cl:format cl:nil "~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <NMotionCtrl_ReadMotionStatus_srv-request>))
  (cl:+ 0
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <NMotionCtrl_ReadMotionStatus_srv-request>))
  "Converts a ROS message object to a list"
  (cl:list 'NMotionCtrl_ReadMotionStatus_srv-request
))
;//! \htmlinclude NMotionCtrl_ReadMotionStatus_srv-response.msg.html

(cl:defclass <NMotionCtrl_ReadMotionStatus_srv-response> (roslisp-msg-protocol:ros-message)
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
   (u8MotionStatus
    :reader u8MotionStatus
    :initarg :u8MotionStatus
    :type cl:fixnum
    :initform 0)
   (u8SysErrStatus
    :reader u8SysErrStatus
    :initarg :u8SysErrStatus
    :type cl:fixnum
    :initform 0)
   (u8MotorErrStatus
    :reader u8MotorErrStatus
    :initarg :u8MotorErrStatus
    :type cl:fixnum
    :initform 0)
   (u8MotionBufCnt
    :reader u8MotionBufCnt
    :initarg :u8MotionBufCnt
    :type cl:fixnum
    :initform 0)
   (u8CrtMotionBufAddr
    :reader u8CrtMotionBufAddr
    :initarg :u8CrtMotionBufAddr
    :type cl:fixnum
    :initform 0)
   (u8CmdBufCnt
    :reader u8CmdBufCnt
    :initarg :u8CmdBufCnt
    :type cl:fixnum
    :initform 0)
   (u8CrtCmdBufAddr
    :reader u8CrtCmdBufAddr
    :initarg :u8CrtCmdBufAddr
    :type cl:fixnum
    :initform 0))
)

(cl:defclass NMotionCtrl_ReadMotionStatus_srv-response (<NMotionCtrl_ReadMotionStatus_srv-response>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <NMotionCtrl_ReadMotionStatus_srv-response>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'NMotionCtrl_ReadMotionStatus_srv-response)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name N_Robot-srv:<NMotionCtrl_ReadMotionStatus_srv-response> is deprecated: use N_Robot-srv:NMotionCtrl_ReadMotionStatus_srv-response instead.")))

(cl:ensure-generic-function 's32ErrCode-val :lambda-list '(m))
(cl:defmethod s32ErrCode-val ((m <NMotionCtrl_ReadMotionStatus_srv-response>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader N_Robot-srv:s32ErrCode-val is deprecated.  Use N_Robot-srv:s32ErrCode instead.")
  (s32ErrCode m))

(cl:ensure-generic-function 'strErrInfo-val :lambda-list '(m))
(cl:defmethod strErrInfo-val ((m <NMotionCtrl_ReadMotionStatus_srv-response>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader N_Robot-srv:strErrInfo-val is deprecated.  Use N_Robot-srv:strErrInfo instead.")
  (strErrInfo m))

(cl:ensure-generic-function 'u8MotionStatus-val :lambda-list '(m))
(cl:defmethod u8MotionStatus-val ((m <NMotionCtrl_ReadMotionStatus_srv-response>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader N_Robot-srv:u8MotionStatus-val is deprecated.  Use N_Robot-srv:u8MotionStatus instead.")
  (u8MotionStatus m))

(cl:ensure-generic-function 'u8SysErrStatus-val :lambda-list '(m))
(cl:defmethod u8SysErrStatus-val ((m <NMotionCtrl_ReadMotionStatus_srv-response>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader N_Robot-srv:u8SysErrStatus-val is deprecated.  Use N_Robot-srv:u8SysErrStatus instead.")
  (u8SysErrStatus m))

(cl:ensure-generic-function 'u8MotorErrStatus-val :lambda-list '(m))
(cl:defmethod u8MotorErrStatus-val ((m <NMotionCtrl_ReadMotionStatus_srv-response>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader N_Robot-srv:u8MotorErrStatus-val is deprecated.  Use N_Robot-srv:u8MotorErrStatus instead.")
  (u8MotorErrStatus m))

(cl:ensure-generic-function 'u8MotionBufCnt-val :lambda-list '(m))
(cl:defmethod u8MotionBufCnt-val ((m <NMotionCtrl_ReadMotionStatus_srv-response>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader N_Robot-srv:u8MotionBufCnt-val is deprecated.  Use N_Robot-srv:u8MotionBufCnt instead.")
  (u8MotionBufCnt m))

(cl:ensure-generic-function 'u8CrtMotionBufAddr-val :lambda-list '(m))
(cl:defmethod u8CrtMotionBufAddr-val ((m <NMotionCtrl_ReadMotionStatus_srv-response>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader N_Robot-srv:u8CrtMotionBufAddr-val is deprecated.  Use N_Robot-srv:u8CrtMotionBufAddr instead.")
  (u8CrtMotionBufAddr m))

(cl:ensure-generic-function 'u8CmdBufCnt-val :lambda-list '(m))
(cl:defmethod u8CmdBufCnt-val ((m <NMotionCtrl_ReadMotionStatus_srv-response>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader N_Robot-srv:u8CmdBufCnt-val is deprecated.  Use N_Robot-srv:u8CmdBufCnt instead.")
  (u8CmdBufCnt m))

(cl:ensure-generic-function 'u8CrtCmdBufAddr-val :lambda-list '(m))
(cl:defmethod u8CrtCmdBufAddr-val ((m <NMotionCtrl_ReadMotionStatus_srv-response>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader N_Robot-srv:u8CrtCmdBufAddr-val is deprecated.  Use N_Robot-srv:u8CrtCmdBufAddr instead.")
  (u8CrtCmdBufAddr m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <NMotionCtrl_ReadMotionStatus_srv-response>) ostream)
  "Serializes a message object of type '<NMotionCtrl_ReadMotionStatus_srv-response>"
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
  (cl:write-byte (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'u8MotionStatus)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'u8SysErrStatus)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'u8MotorErrStatus)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'u8MotionBufCnt)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'u8CrtMotionBufAddr)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'u8CmdBufCnt)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'u8CrtCmdBufAddr)) ostream)
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <NMotionCtrl_ReadMotionStatus_srv-response>) istream)
  "Deserializes a message object of type '<NMotionCtrl_ReadMotionStatus_srv-response>"
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
    (cl:setf (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'u8MotionStatus)) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'u8SysErrStatus)) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'u8MotorErrStatus)) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'u8MotionBufCnt)) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'u8CrtMotionBufAddr)) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'u8CmdBufCnt)) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'u8CrtCmdBufAddr)) (cl:read-byte istream))
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<NMotionCtrl_ReadMotionStatus_srv-response>)))
  "Returns string type for a service object of type '<NMotionCtrl_ReadMotionStatus_srv-response>"
  "N_Robot/NMotionCtrl_ReadMotionStatus_srvResponse")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'NMotionCtrl_ReadMotionStatus_srv-response)))
  "Returns string type for a service object of type 'NMotionCtrl_ReadMotionStatus_srv-response"
  "N_Robot/NMotionCtrl_ReadMotionStatus_srvResponse")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<NMotionCtrl_ReadMotionStatus_srv-response>)))
  "Returns md5sum for a message object of type '<NMotionCtrl_ReadMotionStatus_srv-response>"
  "cab3d3372c649fc51ca4cd10570bd6c5")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'NMotionCtrl_ReadMotionStatus_srv-response)))
  "Returns md5sum for a message object of type 'NMotionCtrl_ReadMotionStatus_srv-response"
  "cab3d3372c649fc51ca4cd10570bd6c5")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<NMotionCtrl_ReadMotionStatus_srv-response>)))
  "Returns full string definition for message of type '<NMotionCtrl_ReadMotionStatus_srv-response>"
  (cl:format cl:nil "int32  s32ErrCode~%string strErrInfo~%uint8  u8MotionStatus~%uint8  u8SysErrStatus~%uint8  u8MotorErrStatus~%uint8  u8MotionBufCnt~%uint8  u8CrtMotionBufAddr~%uint8  u8CmdBufCnt~%uint8  u8CrtCmdBufAddr~%~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'NMotionCtrl_ReadMotionStatus_srv-response)))
  "Returns full string definition for message of type 'NMotionCtrl_ReadMotionStatus_srv-response"
  (cl:format cl:nil "int32  s32ErrCode~%string strErrInfo~%uint8  u8MotionStatus~%uint8  u8SysErrStatus~%uint8  u8MotorErrStatus~%uint8  u8MotionBufCnt~%uint8  u8CrtMotionBufAddr~%uint8  u8CmdBufCnt~%uint8  u8CrtCmdBufAddr~%~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <NMotionCtrl_ReadMotionStatus_srv-response>))
  (cl:+ 0
     4
     4 (cl:length (cl:slot-value msg 'strErrInfo))
     1
     1
     1
     1
     1
     1
     1
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <NMotionCtrl_ReadMotionStatus_srv-response>))
  "Converts a ROS message object to a list"
  (cl:list 'NMotionCtrl_ReadMotionStatus_srv-response
    (cl:cons ':s32ErrCode (s32ErrCode msg))
    (cl:cons ':strErrInfo (strErrInfo msg))
    (cl:cons ':u8MotionStatus (u8MotionStatus msg))
    (cl:cons ':u8SysErrStatus (u8SysErrStatus msg))
    (cl:cons ':u8MotorErrStatus (u8MotorErrStatus msg))
    (cl:cons ':u8MotionBufCnt (u8MotionBufCnt msg))
    (cl:cons ':u8CrtMotionBufAddr (u8CrtMotionBufAddr msg))
    (cl:cons ':u8CmdBufCnt (u8CmdBufCnt msg))
    (cl:cons ':u8CrtCmdBufAddr (u8CrtCmdBufAddr msg))
))
(cl:defmethod roslisp-msg-protocol:service-request-type ((msg (cl:eql 'NMotionCtrl_ReadMotionStatus_srv)))
  'NMotionCtrl_ReadMotionStatus_srv-request)
(cl:defmethod roslisp-msg-protocol:service-response-type ((msg (cl:eql 'NMotionCtrl_ReadMotionStatus_srv)))
  'NMotionCtrl_ReadMotionStatus_srv-response)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'NMotionCtrl_ReadMotionStatus_srv)))
  "Returns string type for a service object of type '<NMotionCtrl_ReadMotionStatus_srv>"
  "N_Robot/NMotionCtrl_ReadMotionStatus_srv")