; Auto-generated. Do not edit!


(cl:in-package N_Robot-srv)


;//! \htmlinclude NMotionCtrl_ReadDevInfo_srv-request.msg.html

(cl:defclass <NMotionCtrl_ReadDevInfo_srv-request> (roslisp-msg-protocol:ros-message)
  ()
)

(cl:defclass NMotionCtrl_ReadDevInfo_srv-request (<NMotionCtrl_ReadDevInfo_srv-request>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <NMotionCtrl_ReadDevInfo_srv-request>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'NMotionCtrl_ReadDevInfo_srv-request)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name N_Robot-srv:<NMotionCtrl_ReadDevInfo_srv-request> is deprecated: use N_Robot-srv:NMotionCtrl_ReadDevInfo_srv-request instead.")))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <NMotionCtrl_ReadDevInfo_srv-request>) ostream)
  "Serializes a message object of type '<NMotionCtrl_ReadDevInfo_srv-request>"
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <NMotionCtrl_ReadDevInfo_srv-request>) istream)
  "Deserializes a message object of type '<NMotionCtrl_ReadDevInfo_srv-request>"
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<NMotionCtrl_ReadDevInfo_srv-request>)))
  "Returns string type for a service object of type '<NMotionCtrl_ReadDevInfo_srv-request>"
  "N_Robot/NMotionCtrl_ReadDevInfo_srvRequest")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'NMotionCtrl_ReadDevInfo_srv-request)))
  "Returns string type for a service object of type 'NMotionCtrl_ReadDevInfo_srv-request"
  "N_Robot/NMotionCtrl_ReadDevInfo_srvRequest")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<NMotionCtrl_ReadDevInfo_srv-request>)))
  "Returns md5sum for a message object of type '<NMotionCtrl_ReadDevInfo_srv-request>"
  "4ac4faa8af4fa35586775683b4a29d63")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'NMotionCtrl_ReadDevInfo_srv-request)))
  "Returns md5sum for a message object of type 'NMotionCtrl_ReadDevInfo_srv-request"
  "4ac4faa8af4fa35586775683b4a29d63")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<NMotionCtrl_ReadDevInfo_srv-request>)))
  "Returns full string definition for message of type '<NMotionCtrl_ReadDevInfo_srv-request>"
  (cl:format cl:nil "~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'NMotionCtrl_ReadDevInfo_srv-request)))
  "Returns full string definition for message of type 'NMotionCtrl_ReadDevInfo_srv-request"
  (cl:format cl:nil "~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <NMotionCtrl_ReadDevInfo_srv-request>))
  (cl:+ 0
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <NMotionCtrl_ReadDevInfo_srv-request>))
  "Converts a ROS message object to a list"
  (cl:list 'NMotionCtrl_ReadDevInfo_srv-request
))
;//! \htmlinclude NMotionCtrl_ReadDevInfo_srv-response.msg.html

(cl:defclass <NMotionCtrl_ReadDevInfo_srv-response> (roslisp-msg-protocol:ros-message)
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
   (u8DevAddr
    :reader u8DevAddr
    :initarg :u8DevAddr
    :type cl:fixnum
    :initform 0)
   (u8DevType
    :reader u8DevType
    :initarg :u8DevType
    :type cl:fixnum
    :initform 0)
   (u32DevSN
    :reader u32DevSN
    :initarg :u32DevSN
    :type cl:integer
    :initform 0))
)

(cl:defclass NMotionCtrl_ReadDevInfo_srv-response (<NMotionCtrl_ReadDevInfo_srv-response>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <NMotionCtrl_ReadDevInfo_srv-response>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'NMotionCtrl_ReadDevInfo_srv-response)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name N_Robot-srv:<NMotionCtrl_ReadDevInfo_srv-response> is deprecated: use N_Robot-srv:NMotionCtrl_ReadDevInfo_srv-response instead.")))

(cl:ensure-generic-function 's32ErrCode-val :lambda-list '(m))
(cl:defmethod s32ErrCode-val ((m <NMotionCtrl_ReadDevInfo_srv-response>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader N_Robot-srv:s32ErrCode-val is deprecated.  Use N_Robot-srv:s32ErrCode instead.")
  (s32ErrCode m))

(cl:ensure-generic-function 'strErrInfo-val :lambda-list '(m))
(cl:defmethod strErrInfo-val ((m <NMotionCtrl_ReadDevInfo_srv-response>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader N_Robot-srv:strErrInfo-val is deprecated.  Use N_Robot-srv:strErrInfo instead.")
  (strErrInfo m))

(cl:ensure-generic-function 'u8DevAddr-val :lambda-list '(m))
(cl:defmethod u8DevAddr-val ((m <NMotionCtrl_ReadDevInfo_srv-response>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader N_Robot-srv:u8DevAddr-val is deprecated.  Use N_Robot-srv:u8DevAddr instead.")
  (u8DevAddr m))

(cl:ensure-generic-function 'u8DevType-val :lambda-list '(m))
(cl:defmethod u8DevType-val ((m <NMotionCtrl_ReadDevInfo_srv-response>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader N_Robot-srv:u8DevType-val is deprecated.  Use N_Robot-srv:u8DevType instead.")
  (u8DevType m))

(cl:ensure-generic-function 'u32DevSN-val :lambda-list '(m))
(cl:defmethod u32DevSN-val ((m <NMotionCtrl_ReadDevInfo_srv-response>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader N_Robot-srv:u32DevSN-val is deprecated.  Use N_Robot-srv:u32DevSN instead.")
  (u32DevSN m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <NMotionCtrl_ReadDevInfo_srv-response>) ostream)
  "Serializes a message object of type '<NMotionCtrl_ReadDevInfo_srv-response>"
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
  (cl:write-byte (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'u8DevAddr)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'u8DevType)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'u32DevSN)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 8) (cl:slot-value msg 'u32DevSN)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 16) (cl:slot-value msg 'u32DevSN)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 24) (cl:slot-value msg 'u32DevSN)) ostream)
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <NMotionCtrl_ReadDevInfo_srv-response>) istream)
  "Deserializes a message object of type '<NMotionCtrl_ReadDevInfo_srv-response>"
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
    (cl:setf (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'u8DevAddr)) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'u8DevType)) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'u32DevSN)) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 8) (cl:slot-value msg 'u32DevSN)) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 16) (cl:slot-value msg 'u32DevSN)) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 24) (cl:slot-value msg 'u32DevSN)) (cl:read-byte istream))
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<NMotionCtrl_ReadDevInfo_srv-response>)))
  "Returns string type for a service object of type '<NMotionCtrl_ReadDevInfo_srv-response>"
  "N_Robot/NMotionCtrl_ReadDevInfo_srvResponse")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'NMotionCtrl_ReadDevInfo_srv-response)))
  "Returns string type for a service object of type 'NMotionCtrl_ReadDevInfo_srv-response"
  "N_Robot/NMotionCtrl_ReadDevInfo_srvResponse")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<NMotionCtrl_ReadDevInfo_srv-response>)))
  "Returns md5sum for a message object of type '<NMotionCtrl_ReadDevInfo_srv-response>"
  "4ac4faa8af4fa35586775683b4a29d63")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'NMotionCtrl_ReadDevInfo_srv-response)))
  "Returns md5sum for a message object of type 'NMotionCtrl_ReadDevInfo_srv-response"
  "4ac4faa8af4fa35586775683b4a29d63")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<NMotionCtrl_ReadDevInfo_srv-response>)))
  "Returns full string definition for message of type '<NMotionCtrl_ReadDevInfo_srv-response>"
  (cl:format cl:nil "int32  s32ErrCode~%string strErrInfo~%uint8  u8DevAddr~%uint8  u8DevType~%uint32 u32DevSN~%~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'NMotionCtrl_ReadDevInfo_srv-response)))
  "Returns full string definition for message of type 'NMotionCtrl_ReadDevInfo_srv-response"
  (cl:format cl:nil "int32  s32ErrCode~%string strErrInfo~%uint8  u8DevAddr~%uint8  u8DevType~%uint32 u32DevSN~%~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <NMotionCtrl_ReadDevInfo_srv-response>))
  (cl:+ 0
     4
     4 (cl:length (cl:slot-value msg 'strErrInfo))
     1
     1
     4
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <NMotionCtrl_ReadDevInfo_srv-response>))
  "Converts a ROS message object to a list"
  (cl:list 'NMotionCtrl_ReadDevInfo_srv-response
    (cl:cons ':s32ErrCode (s32ErrCode msg))
    (cl:cons ':strErrInfo (strErrInfo msg))
    (cl:cons ':u8DevAddr (u8DevAddr msg))
    (cl:cons ':u8DevType (u8DevType msg))
    (cl:cons ':u32DevSN (u32DevSN msg))
))
(cl:defmethod roslisp-msg-protocol:service-request-type ((msg (cl:eql 'NMotionCtrl_ReadDevInfo_srv)))
  'NMotionCtrl_ReadDevInfo_srv-request)
(cl:defmethod roslisp-msg-protocol:service-response-type ((msg (cl:eql 'NMotionCtrl_ReadDevInfo_srv)))
  'NMotionCtrl_ReadDevInfo_srv-response)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'NMotionCtrl_ReadDevInfo_srv)))
  "Returns string type for a service object of type '<NMotionCtrl_ReadDevInfo_srv>"
  "N_Robot/NMotionCtrl_ReadDevInfo_srv")