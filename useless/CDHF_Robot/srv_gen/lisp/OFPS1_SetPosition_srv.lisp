; Auto-generated. Do not edit!


(cl:in-package N_Robot-srv)


;//! \htmlinclude OFPS1_SetPosition_srv-request.msg.html

(cl:defclass <OFPS1_SetPosition_srv-request> (roslisp-msg-protocol:ros-message)
  ((f32PositionX
    :reader f32PositionX
    :initarg :f32PositionX
    :type cl:float
    :initform 0.0)
   (f32PositionY
    :reader f32PositionY
    :initarg :f32PositionY
    :type cl:float
    :initform 0.0)
   (f32PositionTh
    :reader f32PositionTh
    :initarg :f32PositionTh
    :type cl:float
    :initform 0.0))
)

(cl:defclass OFPS1_SetPosition_srv-request (<OFPS1_SetPosition_srv-request>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <OFPS1_SetPosition_srv-request>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'OFPS1_SetPosition_srv-request)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name N_Robot-srv:<OFPS1_SetPosition_srv-request> is deprecated: use N_Robot-srv:OFPS1_SetPosition_srv-request instead.")))

(cl:ensure-generic-function 'f32PositionX-val :lambda-list '(m))
(cl:defmethod f32PositionX-val ((m <OFPS1_SetPosition_srv-request>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader N_Robot-srv:f32PositionX-val is deprecated.  Use N_Robot-srv:f32PositionX instead.")
  (f32PositionX m))

(cl:ensure-generic-function 'f32PositionY-val :lambda-list '(m))
(cl:defmethod f32PositionY-val ((m <OFPS1_SetPosition_srv-request>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader N_Robot-srv:f32PositionY-val is deprecated.  Use N_Robot-srv:f32PositionY instead.")
  (f32PositionY m))

(cl:ensure-generic-function 'f32PositionTh-val :lambda-list '(m))
(cl:defmethod f32PositionTh-val ((m <OFPS1_SetPosition_srv-request>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader N_Robot-srv:f32PositionTh-val is deprecated.  Use N_Robot-srv:f32PositionTh instead.")
  (f32PositionTh m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <OFPS1_SetPosition_srv-request>) ostream)
  "Serializes a message object of type '<OFPS1_SetPosition_srv-request>"
  (cl:let ((bits (roslisp-utils:encode-single-float-bits (cl:slot-value msg 'f32PositionX))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream))
  (cl:let ((bits (roslisp-utils:encode-single-float-bits (cl:slot-value msg 'f32PositionY))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream))
  (cl:let ((bits (roslisp-utils:encode-single-float-bits (cl:slot-value msg 'f32PositionTh))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream))
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <OFPS1_SetPosition_srv-request>) istream)
  "Deserializes a message object of type '<OFPS1_SetPosition_srv-request>"
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
    (cl:setf (cl:slot-value msg 'f32PositionX) (roslisp-utils:decode-single-float-bits bits)))
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
    (cl:setf (cl:slot-value msg 'f32PositionY) (roslisp-utils:decode-single-float-bits bits)))
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
    (cl:setf (cl:slot-value msg 'f32PositionTh) (roslisp-utils:decode-single-float-bits bits)))
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<OFPS1_SetPosition_srv-request>)))
  "Returns string type for a service object of type '<OFPS1_SetPosition_srv-request>"
  "N_Robot/OFPS1_SetPosition_srvRequest")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'OFPS1_SetPosition_srv-request)))
  "Returns string type for a service object of type 'OFPS1_SetPosition_srv-request"
  "N_Robot/OFPS1_SetPosition_srvRequest")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<OFPS1_SetPosition_srv-request>)))
  "Returns md5sum for a message object of type '<OFPS1_SetPosition_srv-request>"
  "6ca74b599d4416d50467dc8670b61405")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'OFPS1_SetPosition_srv-request)))
  "Returns md5sum for a message object of type 'OFPS1_SetPosition_srv-request"
  "6ca74b599d4416d50467dc8670b61405")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<OFPS1_SetPosition_srv-request>)))
  "Returns full string definition for message of type '<OFPS1_SetPosition_srv-request>"
  (cl:format cl:nil "float32  f32PositionX~%float32  f32PositionY~%float32  f32PositionTh~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'OFPS1_SetPosition_srv-request)))
  "Returns full string definition for message of type 'OFPS1_SetPosition_srv-request"
  (cl:format cl:nil "float32  f32PositionX~%float32  f32PositionY~%float32  f32PositionTh~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <OFPS1_SetPosition_srv-request>))
  (cl:+ 0
     4
     4
     4
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <OFPS1_SetPosition_srv-request>))
  "Converts a ROS message object to a list"
  (cl:list 'OFPS1_SetPosition_srv-request
    (cl:cons ':f32PositionX (f32PositionX msg))
    (cl:cons ':f32PositionY (f32PositionY msg))
    (cl:cons ':f32PositionTh (f32PositionTh msg))
))
;//! \htmlinclude OFPS1_SetPosition_srv-response.msg.html

(cl:defclass <OFPS1_SetPosition_srv-response> (roslisp-msg-protocol:ros-message)
  ((s32ErrCode
    :reader s32ErrCode
    :initarg :s32ErrCode
    :type cl:integer
    :initform 0)
   (strErrInfo
    :reader strErrInfo
    :initarg :strErrInfo
    :type cl:string
    :initform ""))
)

(cl:defclass OFPS1_SetPosition_srv-response (<OFPS1_SetPosition_srv-response>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <OFPS1_SetPosition_srv-response>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'OFPS1_SetPosition_srv-response)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name N_Robot-srv:<OFPS1_SetPosition_srv-response> is deprecated: use N_Robot-srv:OFPS1_SetPosition_srv-response instead.")))

(cl:ensure-generic-function 's32ErrCode-val :lambda-list '(m))
(cl:defmethod s32ErrCode-val ((m <OFPS1_SetPosition_srv-response>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader N_Robot-srv:s32ErrCode-val is deprecated.  Use N_Robot-srv:s32ErrCode instead.")
  (s32ErrCode m))

(cl:ensure-generic-function 'strErrInfo-val :lambda-list '(m))
(cl:defmethod strErrInfo-val ((m <OFPS1_SetPosition_srv-response>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader N_Robot-srv:strErrInfo-val is deprecated.  Use N_Robot-srv:strErrInfo instead.")
  (strErrInfo m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <OFPS1_SetPosition_srv-response>) ostream)
  "Serializes a message object of type '<OFPS1_SetPosition_srv-response>"
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
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <OFPS1_SetPosition_srv-response>) istream)
  "Deserializes a message object of type '<OFPS1_SetPosition_srv-response>"
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
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<OFPS1_SetPosition_srv-response>)))
  "Returns string type for a service object of type '<OFPS1_SetPosition_srv-response>"
  "N_Robot/OFPS1_SetPosition_srvResponse")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'OFPS1_SetPosition_srv-response)))
  "Returns string type for a service object of type 'OFPS1_SetPosition_srv-response"
  "N_Robot/OFPS1_SetPosition_srvResponse")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<OFPS1_SetPosition_srv-response>)))
  "Returns md5sum for a message object of type '<OFPS1_SetPosition_srv-response>"
  "6ca74b599d4416d50467dc8670b61405")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'OFPS1_SetPosition_srv-response)))
  "Returns md5sum for a message object of type 'OFPS1_SetPosition_srv-response"
  "6ca74b599d4416d50467dc8670b61405")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<OFPS1_SetPosition_srv-response>)))
  "Returns full string definition for message of type '<OFPS1_SetPosition_srv-response>"
  (cl:format cl:nil "int32  s32ErrCode~%string strErrInfo~%~%~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'OFPS1_SetPosition_srv-response)))
  "Returns full string definition for message of type 'OFPS1_SetPosition_srv-response"
  (cl:format cl:nil "int32  s32ErrCode~%string strErrInfo~%~%~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <OFPS1_SetPosition_srv-response>))
  (cl:+ 0
     4
     4 (cl:length (cl:slot-value msg 'strErrInfo))
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <OFPS1_SetPosition_srv-response>))
  "Converts a ROS message object to a list"
  (cl:list 'OFPS1_SetPosition_srv-response
    (cl:cons ':s32ErrCode (s32ErrCode msg))
    (cl:cons ':strErrInfo (strErrInfo msg))
))
(cl:defmethod roslisp-msg-protocol:service-request-type ((msg (cl:eql 'OFPS1_SetPosition_srv)))
  'OFPS1_SetPosition_srv-request)
(cl:defmethod roslisp-msg-protocol:service-response-type ((msg (cl:eql 'OFPS1_SetPosition_srv)))
  'OFPS1_SetPosition_srv-response)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'OFPS1_SetPosition_srv)))
  "Returns string type for a service object of type '<OFPS1_SetPosition_srv>"
  "N_Robot/OFPS1_SetPosition_srv")