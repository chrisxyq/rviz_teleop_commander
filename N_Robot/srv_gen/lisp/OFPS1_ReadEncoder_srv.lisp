; Auto-generated. Do not edit!


(cl:in-package N_Robot-srv)


;//! \htmlinclude OFPS1_ReadEncoder_srv-request.msg.html

(cl:defclass <OFPS1_ReadEncoder_srv-request> (roslisp-msg-protocol:ros-message)
  ()
)

(cl:defclass OFPS1_ReadEncoder_srv-request (<OFPS1_ReadEncoder_srv-request>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <OFPS1_ReadEncoder_srv-request>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'OFPS1_ReadEncoder_srv-request)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name N_Robot-srv:<OFPS1_ReadEncoder_srv-request> is deprecated: use N_Robot-srv:OFPS1_ReadEncoder_srv-request instead.")))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <OFPS1_ReadEncoder_srv-request>) ostream)
  "Serializes a message object of type '<OFPS1_ReadEncoder_srv-request>"
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <OFPS1_ReadEncoder_srv-request>) istream)
  "Deserializes a message object of type '<OFPS1_ReadEncoder_srv-request>"
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<OFPS1_ReadEncoder_srv-request>)))
  "Returns string type for a service object of type '<OFPS1_ReadEncoder_srv-request>"
  "N_Robot/OFPS1_ReadEncoder_srvRequest")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'OFPS1_ReadEncoder_srv-request)))
  "Returns string type for a service object of type 'OFPS1_ReadEncoder_srv-request"
  "N_Robot/OFPS1_ReadEncoder_srvRequest")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<OFPS1_ReadEncoder_srv-request>)))
  "Returns md5sum for a message object of type '<OFPS1_ReadEncoder_srv-request>"
  "fde9ee8a9f7ccc3f22d8f39b640b16d0")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'OFPS1_ReadEncoder_srv-request)))
  "Returns md5sum for a message object of type 'OFPS1_ReadEncoder_srv-request"
  "fde9ee8a9f7ccc3f22d8f39b640b16d0")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<OFPS1_ReadEncoder_srv-request>)))
  "Returns full string definition for message of type '<OFPS1_ReadEncoder_srv-request>"
  (cl:format cl:nil "~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'OFPS1_ReadEncoder_srv-request)))
  "Returns full string definition for message of type 'OFPS1_ReadEncoder_srv-request"
  (cl:format cl:nil "~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <OFPS1_ReadEncoder_srv-request>))
  (cl:+ 0
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <OFPS1_ReadEncoder_srv-request>))
  "Converts a ROS message object to a list"
  (cl:list 'OFPS1_ReadEncoder_srv-request
))
;//! \htmlinclude OFPS1_ReadEncoder_srv-response.msg.html

(cl:defclass <OFPS1_ReadEncoder_srv-response> (roslisp-msg-protocol:ros-message)
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
   (f32Encoder1
    :reader f32Encoder1
    :initarg :f32Encoder1
    :type cl:float
    :initform 0.0)
   (f32Encoder2
    :reader f32Encoder2
    :initarg :f32Encoder2
    :type cl:float
    :initform 0.0)
   (f32Encoder3
    :reader f32Encoder3
    :initarg :f32Encoder3
    :type cl:float
    :initform 0.0))
)

(cl:defclass OFPS1_ReadEncoder_srv-response (<OFPS1_ReadEncoder_srv-response>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <OFPS1_ReadEncoder_srv-response>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'OFPS1_ReadEncoder_srv-response)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name N_Robot-srv:<OFPS1_ReadEncoder_srv-response> is deprecated: use N_Robot-srv:OFPS1_ReadEncoder_srv-response instead.")))

(cl:ensure-generic-function 's32ErrCode-val :lambda-list '(m))
(cl:defmethod s32ErrCode-val ((m <OFPS1_ReadEncoder_srv-response>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader N_Robot-srv:s32ErrCode-val is deprecated.  Use N_Robot-srv:s32ErrCode instead.")
  (s32ErrCode m))

(cl:ensure-generic-function 'strErrInfo-val :lambda-list '(m))
(cl:defmethod strErrInfo-val ((m <OFPS1_ReadEncoder_srv-response>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader N_Robot-srv:strErrInfo-val is deprecated.  Use N_Robot-srv:strErrInfo instead.")
  (strErrInfo m))

(cl:ensure-generic-function 'f32Encoder1-val :lambda-list '(m))
(cl:defmethod f32Encoder1-val ((m <OFPS1_ReadEncoder_srv-response>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader N_Robot-srv:f32Encoder1-val is deprecated.  Use N_Robot-srv:f32Encoder1 instead.")
  (f32Encoder1 m))

(cl:ensure-generic-function 'f32Encoder2-val :lambda-list '(m))
(cl:defmethod f32Encoder2-val ((m <OFPS1_ReadEncoder_srv-response>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader N_Robot-srv:f32Encoder2-val is deprecated.  Use N_Robot-srv:f32Encoder2 instead.")
  (f32Encoder2 m))

(cl:ensure-generic-function 'f32Encoder3-val :lambda-list '(m))
(cl:defmethod f32Encoder3-val ((m <OFPS1_ReadEncoder_srv-response>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader N_Robot-srv:f32Encoder3-val is deprecated.  Use N_Robot-srv:f32Encoder3 instead.")
  (f32Encoder3 m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <OFPS1_ReadEncoder_srv-response>) ostream)
  "Serializes a message object of type '<OFPS1_ReadEncoder_srv-response>"
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
  (cl:let ((bits (roslisp-utils:encode-single-float-bits (cl:slot-value msg 'f32Encoder1))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream))
  (cl:let ((bits (roslisp-utils:encode-single-float-bits (cl:slot-value msg 'f32Encoder2))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream))
  (cl:let ((bits (roslisp-utils:encode-single-float-bits (cl:slot-value msg 'f32Encoder3))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream))
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <OFPS1_ReadEncoder_srv-response>) istream)
  "Deserializes a message object of type '<OFPS1_ReadEncoder_srv-response>"
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
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
    (cl:setf (cl:slot-value msg 'f32Encoder1) (roslisp-utils:decode-single-float-bits bits)))
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
    (cl:setf (cl:slot-value msg 'f32Encoder2) (roslisp-utils:decode-single-float-bits bits)))
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
    (cl:setf (cl:slot-value msg 'f32Encoder3) (roslisp-utils:decode-single-float-bits bits)))
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<OFPS1_ReadEncoder_srv-response>)))
  "Returns string type for a service object of type '<OFPS1_ReadEncoder_srv-response>"
  "N_Robot/OFPS1_ReadEncoder_srvResponse")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'OFPS1_ReadEncoder_srv-response)))
  "Returns string type for a service object of type 'OFPS1_ReadEncoder_srv-response"
  "N_Robot/OFPS1_ReadEncoder_srvResponse")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<OFPS1_ReadEncoder_srv-response>)))
  "Returns md5sum for a message object of type '<OFPS1_ReadEncoder_srv-response>"
  "fde9ee8a9f7ccc3f22d8f39b640b16d0")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'OFPS1_ReadEncoder_srv-response)))
  "Returns md5sum for a message object of type 'OFPS1_ReadEncoder_srv-response"
  "fde9ee8a9f7ccc3f22d8f39b640b16d0")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<OFPS1_ReadEncoder_srv-response>)))
  "Returns full string definition for message of type '<OFPS1_ReadEncoder_srv-response>"
  (cl:format cl:nil "int32  s32ErrCode~%string strErrInfo~%float32  f32Encoder1~%float32  f32Encoder2~%float32  f32Encoder3~%~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'OFPS1_ReadEncoder_srv-response)))
  "Returns full string definition for message of type 'OFPS1_ReadEncoder_srv-response"
  (cl:format cl:nil "int32  s32ErrCode~%string strErrInfo~%float32  f32Encoder1~%float32  f32Encoder2~%float32  f32Encoder3~%~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <OFPS1_ReadEncoder_srv-response>))
  (cl:+ 0
     4
     4 (cl:length (cl:slot-value msg 'strErrInfo))
     4
     4
     4
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <OFPS1_ReadEncoder_srv-response>))
  "Converts a ROS message object to a list"
  (cl:list 'OFPS1_ReadEncoder_srv-response
    (cl:cons ':s32ErrCode (s32ErrCode msg))
    (cl:cons ':strErrInfo (strErrInfo msg))
    (cl:cons ':f32Encoder1 (f32Encoder1 msg))
    (cl:cons ':f32Encoder2 (f32Encoder2 msg))
    (cl:cons ':f32Encoder3 (f32Encoder3 msg))
))
(cl:defmethod roslisp-msg-protocol:service-request-type ((msg (cl:eql 'OFPS1_ReadEncoder_srv)))
  'OFPS1_ReadEncoder_srv-request)
(cl:defmethod roslisp-msg-protocol:service-response-type ((msg (cl:eql 'OFPS1_ReadEncoder_srv)))
  'OFPS1_ReadEncoder_srv-response)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'OFPS1_ReadEncoder_srv)))
  "Returns string type for a service object of type '<OFPS1_ReadEncoder_srv>"
  "N_Robot/OFPS1_ReadEncoder_srv")