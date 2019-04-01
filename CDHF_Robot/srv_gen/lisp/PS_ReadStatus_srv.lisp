; Auto-generated. Do not edit!


(cl:in-package N_Robot-srv)


;//! \htmlinclude PS_ReadStatus_srv-request.msg.html

(cl:defclass <PS_ReadStatus_srv-request> (roslisp-msg-protocol:ros-message)
  ()
)

(cl:defclass PS_ReadStatus_srv-request (<PS_ReadStatus_srv-request>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <PS_ReadStatus_srv-request>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'PS_ReadStatus_srv-request)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name N_Robot-srv:<PS_ReadStatus_srv-request> is deprecated: use N_Robot-srv:PS_ReadStatus_srv-request instead.")))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <PS_ReadStatus_srv-request>) ostream)
  "Serializes a message object of type '<PS_ReadStatus_srv-request>"
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <PS_ReadStatus_srv-request>) istream)
  "Deserializes a message object of type '<PS_ReadStatus_srv-request>"
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<PS_ReadStatus_srv-request>)))
  "Returns string type for a service object of type '<PS_ReadStatus_srv-request>"
  "N_Robot/PS_ReadStatus_srvRequest")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'PS_ReadStatus_srv-request)))
  "Returns string type for a service object of type 'PS_ReadStatus_srv-request"
  "N_Robot/PS_ReadStatus_srvRequest")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<PS_ReadStatus_srv-request>)))
  "Returns md5sum for a message object of type '<PS_ReadStatus_srv-request>"
  "733c182a56016889a83d22c5e6a7517f")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'PS_ReadStatus_srv-request)))
  "Returns md5sum for a message object of type 'PS_ReadStatus_srv-request"
  "733c182a56016889a83d22c5e6a7517f")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<PS_ReadStatus_srv-request>)))
  "Returns full string definition for message of type '<PS_ReadStatus_srv-request>"
  (cl:format cl:nil "~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'PS_ReadStatus_srv-request)))
  "Returns full string definition for message of type 'PS_ReadStatus_srv-request"
  (cl:format cl:nil "~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <PS_ReadStatus_srv-request>))
  (cl:+ 0
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <PS_ReadStatus_srv-request>))
  "Converts a ROS message object to a list"
  (cl:list 'PS_ReadStatus_srv-request
))
;//! \htmlinclude PS_ReadStatus_srv-response.msg.html

(cl:defclass <PS_ReadStatus_srv-response> (roslisp-msg-protocol:ros-message)
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
   (u8BattOpen
    :reader u8BattOpen
    :initarg :u8BattOpen
    :type cl:fixnum
    :initform 0)
   (u8SwitchDown
    :reader u8SwitchDown
    :initarg :u8SwitchDown
    :type cl:fixnum
    :initform 0)
   (u8ChargerIn
    :reader u8ChargerIn
    :initarg :u8ChargerIn
    :type cl:fixnum
    :initform 0)
   (u8ChargeComp
    :reader u8ChargeComp
    :initarg :u8ChargeComp
    :type cl:fixnum
    :initform 0)
   (u8ChargeOverFlow
    :reader u8ChargeOverFlow
    :initarg :u8ChargeOverFlow
    :type cl:fixnum
    :initform 0)
   (u8ChargerOverVolt
    :reader u8ChargerOverVolt
    :initarg :u8ChargerOverVolt
    :type cl:fixnum
    :initform 0)
   (u8ChargerVoltLow
    :reader u8ChargerVoltLow
    :initarg :u8ChargerVoltLow
    :type cl:fixnum
    :initform 0)
   (u8ChargerOverFlow
    :reader u8ChargerOverFlow
    :initarg :u8ChargerOverFlow
    :type cl:fixnum
    :initform 0))
)

(cl:defclass PS_ReadStatus_srv-response (<PS_ReadStatus_srv-response>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <PS_ReadStatus_srv-response>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'PS_ReadStatus_srv-response)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name N_Robot-srv:<PS_ReadStatus_srv-response> is deprecated: use N_Robot-srv:PS_ReadStatus_srv-response instead.")))

(cl:ensure-generic-function 's32ErrCode-val :lambda-list '(m))
(cl:defmethod s32ErrCode-val ((m <PS_ReadStatus_srv-response>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader N_Robot-srv:s32ErrCode-val is deprecated.  Use N_Robot-srv:s32ErrCode instead.")
  (s32ErrCode m))

(cl:ensure-generic-function 'strErrInfo-val :lambda-list '(m))
(cl:defmethod strErrInfo-val ((m <PS_ReadStatus_srv-response>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader N_Robot-srv:strErrInfo-val is deprecated.  Use N_Robot-srv:strErrInfo instead.")
  (strErrInfo m))

(cl:ensure-generic-function 'u8BattOpen-val :lambda-list '(m))
(cl:defmethod u8BattOpen-val ((m <PS_ReadStatus_srv-response>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader N_Robot-srv:u8BattOpen-val is deprecated.  Use N_Robot-srv:u8BattOpen instead.")
  (u8BattOpen m))

(cl:ensure-generic-function 'u8SwitchDown-val :lambda-list '(m))
(cl:defmethod u8SwitchDown-val ((m <PS_ReadStatus_srv-response>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader N_Robot-srv:u8SwitchDown-val is deprecated.  Use N_Robot-srv:u8SwitchDown instead.")
  (u8SwitchDown m))

(cl:ensure-generic-function 'u8ChargerIn-val :lambda-list '(m))
(cl:defmethod u8ChargerIn-val ((m <PS_ReadStatus_srv-response>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader N_Robot-srv:u8ChargerIn-val is deprecated.  Use N_Robot-srv:u8ChargerIn instead.")
  (u8ChargerIn m))

(cl:ensure-generic-function 'u8ChargeComp-val :lambda-list '(m))
(cl:defmethod u8ChargeComp-val ((m <PS_ReadStatus_srv-response>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader N_Robot-srv:u8ChargeComp-val is deprecated.  Use N_Robot-srv:u8ChargeComp instead.")
  (u8ChargeComp m))

(cl:ensure-generic-function 'u8ChargeOverFlow-val :lambda-list '(m))
(cl:defmethod u8ChargeOverFlow-val ((m <PS_ReadStatus_srv-response>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader N_Robot-srv:u8ChargeOverFlow-val is deprecated.  Use N_Robot-srv:u8ChargeOverFlow instead.")
  (u8ChargeOverFlow m))

(cl:ensure-generic-function 'u8ChargerOverVolt-val :lambda-list '(m))
(cl:defmethod u8ChargerOverVolt-val ((m <PS_ReadStatus_srv-response>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader N_Robot-srv:u8ChargerOverVolt-val is deprecated.  Use N_Robot-srv:u8ChargerOverVolt instead.")
  (u8ChargerOverVolt m))

(cl:ensure-generic-function 'u8ChargerVoltLow-val :lambda-list '(m))
(cl:defmethod u8ChargerVoltLow-val ((m <PS_ReadStatus_srv-response>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader N_Robot-srv:u8ChargerVoltLow-val is deprecated.  Use N_Robot-srv:u8ChargerVoltLow instead.")
  (u8ChargerVoltLow m))

(cl:ensure-generic-function 'u8ChargerOverFlow-val :lambda-list '(m))
(cl:defmethod u8ChargerOverFlow-val ((m <PS_ReadStatus_srv-response>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader N_Robot-srv:u8ChargerOverFlow-val is deprecated.  Use N_Robot-srv:u8ChargerOverFlow instead.")
  (u8ChargerOverFlow m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <PS_ReadStatus_srv-response>) ostream)
  "Serializes a message object of type '<PS_ReadStatus_srv-response>"
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
  (cl:write-byte (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'u8BattOpen)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'u8SwitchDown)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'u8ChargerIn)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'u8ChargeComp)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'u8ChargeOverFlow)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'u8ChargerOverVolt)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'u8ChargerVoltLow)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'u8ChargerOverFlow)) ostream)
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <PS_ReadStatus_srv-response>) istream)
  "Deserializes a message object of type '<PS_ReadStatus_srv-response>"
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
    (cl:setf (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'u8BattOpen)) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'u8SwitchDown)) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'u8ChargerIn)) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'u8ChargeComp)) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'u8ChargeOverFlow)) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'u8ChargerOverVolt)) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'u8ChargerVoltLow)) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'u8ChargerOverFlow)) (cl:read-byte istream))
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<PS_ReadStatus_srv-response>)))
  "Returns string type for a service object of type '<PS_ReadStatus_srv-response>"
  "N_Robot/PS_ReadStatus_srvResponse")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'PS_ReadStatus_srv-response)))
  "Returns string type for a service object of type 'PS_ReadStatus_srv-response"
  "N_Robot/PS_ReadStatus_srvResponse")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<PS_ReadStatus_srv-response>)))
  "Returns md5sum for a message object of type '<PS_ReadStatus_srv-response>"
  "733c182a56016889a83d22c5e6a7517f")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'PS_ReadStatus_srv-response)))
  "Returns md5sum for a message object of type 'PS_ReadStatus_srv-response"
  "733c182a56016889a83d22c5e6a7517f")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<PS_ReadStatus_srv-response>)))
  "Returns full string definition for message of type '<PS_ReadStatus_srv-response>"
  (cl:format cl:nil "int32  s32ErrCode~%string strErrInfo~%uint8  u8BattOpen~%uint8  u8SwitchDown~%uint8  u8ChargerIn~%uint8  u8ChargeComp~%uint8  u8ChargeOverFlow~%uint8  u8ChargerOverVolt~%uint8  u8ChargerVoltLow~%uint8  u8ChargerOverFlow~%~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'PS_ReadStatus_srv-response)))
  "Returns full string definition for message of type 'PS_ReadStatus_srv-response"
  (cl:format cl:nil "int32  s32ErrCode~%string strErrInfo~%uint8  u8BattOpen~%uint8  u8SwitchDown~%uint8  u8ChargerIn~%uint8  u8ChargeComp~%uint8  u8ChargeOverFlow~%uint8  u8ChargerOverVolt~%uint8  u8ChargerVoltLow~%uint8  u8ChargerOverFlow~%~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <PS_ReadStatus_srv-response>))
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
     1
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <PS_ReadStatus_srv-response>))
  "Converts a ROS message object to a list"
  (cl:list 'PS_ReadStatus_srv-response
    (cl:cons ':s32ErrCode (s32ErrCode msg))
    (cl:cons ':strErrInfo (strErrInfo msg))
    (cl:cons ':u8BattOpen (u8BattOpen msg))
    (cl:cons ':u8SwitchDown (u8SwitchDown msg))
    (cl:cons ':u8ChargerIn (u8ChargerIn msg))
    (cl:cons ':u8ChargeComp (u8ChargeComp msg))
    (cl:cons ':u8ChargeOverFlow (u8ChargeOverFlow msg))
    (cl:cons ':u8ChargerOverVolt (u8ChargerOverVolt msg))
    (cl:cons ':u8ChargerVoltLow (u8ChargerVoltLow msg))
    (cl:cons ':u8ChargerOverFlow (u8ChargerOverFlow msg))
))
(cl:defmethod roslisp-msg-protocol:service-request-type ((msg (cl:eql 'PS_ReadStatus_srv)))
  'PS_ReadStatus_srv-request)
(cl:defmethod roslisp-msg-protocol:service-response-type ((msg (cl:eql 'PS_ReadStatus_srv)))
  'PS_ReadStatus_srv-response)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'PS_ReadStatus_srv)))
  "Returns string type for a service object of type '<PS_ReadStatus_srv>"
  "N_Robot/PS_ReadStatus_srv")