; Auto-generated. Do not edit!


(cl:in-package N_Robot-srv)


;//! \htmlinclude PBUTTING_ReadStatus_srv-request.msg.html

(cl:defclass <PBUTTING_ReadStatus_srv-request> (roslisp-msg-protocol:ros-message)
  ()
)

(cl:defclass PBUTTING_ReadStatus_srv-request (<PBUTTING_ReadStatus_srv-request>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <PBUTTING_ReadStatus_srv-request>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'PBUTTING_ReadStatus_srv-request)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name N_Robot-srv:<PBUTTING_ReadStatus_srv-request> is deprecated: use N_Robot-srv:PBUTTING_ReadStatus_srv-request instead.")))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <PBUTTING_ReadStatus_srv-request>) ostream)
  "Serializes a message object of type '<PBUTTING_ReadStatus_srv-request>"
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <PBUTTING_ReadStatus_srv-request>) istream)
  "Deserializes a message object of type '<PBUTTING_ReadStatus_srv-request>"
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<PBUTTING_ReadStatus_srv-request>)))
  "Returns string type for a service object of type '<PBUTTING_ReadStatus_srv-request>"
  "N_Robot/PBUTTING_ReadStatus_srvRequest")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'PBUTTING_ReadStatus_srv-request)))
  "Returns string type for a service object of type 'PBUTTING_ReadStatus_srv-request"
  "N_Robot/PBUTTING_ReadStatus_srvRequest")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<PBUTTING_ReadStatus_srv-request>)))
  "Returns md5sum for a message object of type '<PBUTTING_ReadStatus_srv-request>"
  "3713bac249ff5edea25dc7f5bbaac80b")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'PBUTTING_ReadStatus_srv-request)))
  "Returns md5sum for a message object of type 'PBUTTING_ReadStatus_srv-request"
  "3713bac249ff5edea25dc7f5bbaac80b")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<PBUTTING_ReadStatus_srv-request>)))
  "Returns full string definition for message of type '<PBUTTING_ReadStatus_srv-request>"
  (cl:format cl:nil "~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'PBUTTING_ReadStatus_srv-request)))
  "Returns full string definition for message of type 'PBUTTING_ReadStatus_srv-request"
  (cl:format cl:nil "~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <PBUTTING_ReadStatus_srv-request>))
  (cl:+ 0
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <PBUTTING_ReadStatus_srv-request>))
  "Converts a ROS message object to a list"
  (cl:list 'PBUTTING_ReadStatus_srv-request
))
;//! \htmlinclude PBUTTING_ReadStatus_srv-response.msg.html

(cl:defclass <PBUTTING_ReadStatus_srv-response> (roslisp-msg-protocol:ros-message)
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
   (u8Switch
    :reader u8Switch
    :initarg :u8Switch
    :type cl:fixnum
    :initform 0)
   (f32Position
    :reader f32Position
    :initarg :f32Position
    :type cl:float
    :initform 0.0))
)

(cl:defclass PBUTTING_ReadStatus_srv-response (<PBUTTING_ReadStatus_srv-response>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <PBUTTING_ReadStatus_srv-response>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'PBUTTING_ReadStatus_srv-response)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name N_Robot-srv:<PBUTTING_ReadStatus_srv-response> is deprecated: use N_Robot-srv:PBUTTING_ReadStatus_srv-response instead.")))

(cl:ensure-generic-function 's32ErrCode-val :lambda-list '(m))
(cl:defmethod s32ErrCode-val ((m <PBUTTING_ReadStatus_srv-response>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader N_Robot-srv:s32ErrCode-val is deprecated.  Use N_Robot-srv:s32ErrCode instead.")
  (s32ErrCode m))

(cl:ensure-generic-function 'strErrInfo-val :lambda-list '(m))
(cl:defmethod strErrInfo-val ((m <PBUTTING_ReadStatus_srv-response>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader N_Robot-srv:strErrInfo-val is deprecated.  Use N_Robot-srv:strErrInfo instead.")
  (strErrInfo m))

(cl:ensure-generic-function 'u8Switch-val :lambda-list '(m))
(cl:defmethod u8Switch-val ((m <PBUTTING_ReadStatus_srv-response>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader N_Robot-srv:u8Switch-val is deprecated.  Use N_Robot-srv:u8Switch instead.")
  (u8Switch m))

(cl:ensure-generic-function 'f32Position-val :lambda-list '(m))
(cl:defmethod f32Position-val ((m <PBUTTING_ReadStatus_srv-response>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader N_Robot-srv:f32Position-val is deprecated.  Use N_Robot-srv:f32Position instead.")
  (f32Position m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <PBUTTING_ReadStatus_srv-response>) ostream)
  "Serializes a message object of type '<PBUTTING_ReadStatus_srv-response>"
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
  (cl:write-byte (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'u8Switch)) ostream)
  (cl:let ((bits (roslisp-utils:encode-single-float-bits (cl:slot-value msg 'f32Position))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream))
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <PBUTTING_ReadStatus_srv-response>) istream)
  "Deserializes a message object of type '<PBUTTING_ReadStatus_srv-response>"
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
    (cl:setf (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'u8Switch)) (cl:read-byte istream))
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
    (cl:setf (cl:slot-value msg 'f32Position) (roslisp-utils:decode-single-float-bits bits)))
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<PBUTTING_ReadStatus_srv-response>)))
  "Returns string type for a service object of type '<PBUTTING_ReadStatus_srv-response>"
  "N_Robot/PBUTTING_ReadStatus_srvResponse")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'PBUTTING_ReadStatus_srv-response)))
  "Returns string type for a service object of type 'PBUTTING_ReadStatus_srv-response"
  "N_Robot/PBUTTING_ReadStatus_srvResponse")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<PBUTTING_ReadStatus_srv-response>)))
  "Returns md5sum for a message object of type '<PBUTTING_ReadStatus_srv-response>"
  "3713bac249ff5edea25dc7f5bbaac80b")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'PBUTTING_ReadStatus_srv-response)))
  "Returns md5sum for a message object of type 'PBUTTING_ReadStatus_srv-response"
  "3713bac249ff5edea25dc7f5bbaac80b")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<PBUTTING_ReadStatus_srv-response>)))
  "Returns full string definition for message of type '<PBUTTING_ReadStatus_srv-response>"
  (cl:format cl:nil "int32  s32ErrCode~%string strErrInfo~%uint8  u8Switch~%float32 f32Position~%~%~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'PBUTTING_ReadStatus_srv-response)))
  "Returns full string definition for message of type 'PBUTTING_ReadStatus_srv-response"
  (cl:format cl:nil "int32  s32ErrCode~%string strErrInfo~%uint8  u8Switch~%float32 f32Position~%~%~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <PBUTTING_ReadStatus_srv-response>))
  (cl:+ 0
     4
     4 (cl:length (cl:slot-value msg 'strErrInfo))
     1
     4
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <PBUTTING_ReadStatus_srv-response>))
  "Converts a ROS message object to a list"
  (cl:list 'PBUTTING_ReadStatus_srv-response
    (cl:cons ':s32ErrCode (s32ErrCode msg))
    (cl:cons ':strErrInfo (strErrInfo msg))
    (cl:cons ':u8Switch (u8Switch msg))
    (cl:cons ':f32Position (f32Position msg))
))
(cl:defmethod roslisp-msg-protocol:service-request-type ((msg (cl:eql 'PBUTTING_ReadStatus_srv)))
  'PBUTTING_ReadStatus_srv-request)
(cl:defmethod roslisp-msg-protocol:service-response-type ((msg (cl:eql 'PBUTTING_ReadStatus_srv)))
  'PBUTTING_ReadStatus_srv-response)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'PBUTTING_ReadStatus_srv)))
  "Returns string type for a service object of type '<PBUTTING_ReadStatus_srv>"
  "N_Robot/PBUTTING_ReadStatus_srv")