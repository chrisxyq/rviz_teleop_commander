; Auto-generated. Do not edit!


(cl:in-package N_Robot-srv)


;//! \htmlinclude PS_ReadTransData_srv-request.msg.html

(cl:defclass <PS_ReadTransData_srv-request> (roslisp-msg-protocol:ros-message)
  ()
)

(cl:defclass PS_ReadTransData_srv-request (<PS_ReadTransData_srv-request>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <PS_ReadTransData_srv-request>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'PS_ReadTransData_srv-request)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name N_Robot-srv:<PS_ReadTransData_srv-request> is deprecated: use N_Robot-srv:PS_ReadTransData_srv-request instead.")))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <PS_ReadTransData_srv-request>) ostream)
  "Serializes a message object of type '<PS_ReadTransData_srv-request>"
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <PS_ReadTransData_srv-request>) istream)
  "Deserializes a message object of type '<PS_ReadTransData_srv-request>"
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<PS_ReadTransData_srv-request>)))
  "Returns string type for a service object of type '<PS_ReadTransData_srv-request>"
  "N_Robot/PS_ReadTransData_srvRequest")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'PS_ReadTransData_srv-request)))
  "Returns string type for a service object of type 'PS_ReadTransData_srv-request"
  "N_Robot/PS_ReadTransData_srvRequest")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<PS_ReadTransData_srv-request>)))
  "Returns md5sum for a message object of type '<PS_ReadTransData_srv-request>"
  "abaef58b7907806e78b13d105be847a3")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'PS_ReadTransData_srv-request)))
  "Returns md5sum for a message object of type 'PS_ReadTransData_srv-request"
  "abaef58b7907806e78b13d105be847a3")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<PS_ReadTransData_srv-request>)))
  "Returns full string definition for message of type '<PS_ReadTransData_srv-request>"
  (cl:format cl:nil "~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'PS_ReadTransData_srv-request)))
  "Returns full string definition for message of type 'PS_ReadTransData_srv-request"
  (cl:format cl:nil "~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <PS_ReadTransData_srv-request>))
  (cl:+ 0
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <PS_ReadTransData_srv-request>))
  "Converts a ROS message object to a list"
  (cl:list 'PS_ReadTransData_srv-request
))
;//! \htmlinclude PS_ReadTransData_srv-response.msg.html

(cl:defclass <PS_ReadTransData_srv-response> (roslisp-msg-protocol:ros-message)
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
   (u16BattVolt
    :reader u16BattVolt
    :initarg :u16BattVolt
    :type cl:fixnum
    :initform 0)
   (s16BattCurr
    :reader s16BattCurr
    :initarg :s16BattCurr
    :type cl:fixnum
    :initform 0)
   (s16BattChargeCurr
    :reader s16BattChargeCurr
    :initarg :s16BattChargeCurr
    :type cl:fixnum
    :initform 0)
   (u8Temperture
    :reader u8Temperture
    :initarg :u8Temperture
    :type cl:fixnum
    :initform 0))
)

(cl:defclass PS_ReadTransData_srv-response (<PS_ReadTransData_srv-response>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <PS_ReadTransData_srv-response>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'PS_ReadTransData_srv-response)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name N_Robot-srv:<PS_ReadTransData_srv-response> is deprecated: use N_Robot-srv:PS_ReadTransData_srv-response instead.")))

(cl:ensure-generic-function 's32ErrCode-val :lambda-list '(m))
(cl:defmethod s32ErrCode-val ((m <PS_ReadTransData_srv-response>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader N_Robot-srv:s32ErrCode-val is deprecated.  Use N_Robot-srv:s32ErrCode instead.")
  (s32ErrCode m))

(cl:ensure-generic-function 'strErrInfo-val :lambda-list '(m))
(cl:defmethod strErrInfo-val ((m <PS_ReadTransData_srv-response>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader N_Robot-srv:strErrInfo-val is deprecated.  Use N_Robot-srv:strErrInfo instead.")
  (strErrInfo m))

(cl:ensure-generic-function 'u16BattVolt-val :lambda-list '(m))
(cl:defmethod u16BattVolt-val ((m <PS_ReadTransData_srv-response>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader N_Robot-srv:u16BattVolt-val is deprecated.  Use N_Robot-srv:u16BattVolt instead.")
  (u16BattVolt m))

(cl:ensure-generic-function 's16BattCurr-val :lambda-list '(m))
(cl:defmethod s16BattCurr-val ((m <PS_ReadTransData_srv-response>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader N_Robot-srv:s16BattCurr-val is deprecated.  Use N_Robot-srv:s16BattCurr instead.")
  (s16BattCurr m))

(cl:ensure-generic-function 's16BattChargeCurr-val :lambda-list '(m))
(cl:defmethod s16BattChargeCurr-val ((m <PS_ReadTransData_srv-response>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader N_Robot-srv:s16BattChargeCurr-val is deprecated.  Use N_Robot-srv:s16BattChargeCurr instead.")
  (s16BattChargeCurr m))

(cl:ensure-generic-function 'u8Temperture-val :lambda-list '(m))
(cl:defmethod u8Temperture-val ((m <PS_ReadTransData_srv-response>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader N_Robot-srv:u8Temperture-val is deprecated.  Use N_Robot-srv:u8Temperture instead.")
  (u8Temperture m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <PS_ReadTransData_srv-response>) ostream)
  "Serializes a message object of type '<PS_ReadTransData_srv-response>"
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
  (cl:write-byte (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'u16BattVolt)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 8) (cl:slot-value msg 'u16BattVolt)) ostream)
  (cl:let* ((signed (cl:slot-value msg 's16BattCurr)) (unsigned (cl:if (cl:< signed 0) (cl:+ signed 65536) signed)))
    (cl:write-byte (cl:ldb (cl:byte 8 0) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) unsigned) ostream)
    )
  (cl:let* ((signed (cl:slot-value msg 's16BattChargeCurr)) (unsigned (cl:if (cl:< signed 0) (cl:+ signed 65536) signed)))
    (cl:write-byte (cl:ldb (cl:byte 8 0) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) unsigned) ostream)
    )
  (cl:write-byte (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'u8Temperture)) ostream)
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <PS_ReadTransData_srv-response>) istream)
  "Deserializes a message object of type '<PS_ReadTransData_srv-response>"
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
    (cl:setf (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'u16BattVolt)) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 8) (cl:slot-value msg 'u16BattVolt)) (cl:read-byte istream))
    (cl:let ((unsigned 0))
      (cl:setf (cl:ldb (cl:byte 8 0) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) unsigned) (cl:read-byte istream))
      (cl:setf (cl:slot-value msg 's16BattCurr) (cl:if (cl:< unsigned 32768) unsigned (cl:- unsigned 65536))))
    (cl:let ((unsigned 0))
      (cl:setf (cl:ldb (cl:byte 8 0) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) unsigned) (cl:read-byte istream))
      (cl:setf (cl:slot-value msg 's16BattChargeCurr) (cl:if (cl:< unsigned 32768) unsigned (cl:- unsigned 65536))))
    (cl:setf (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'u8Temperture)) (cl:read-byte istream))
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<PS_ReadTransData_srv-response>)))
  "Returns string type for a service object of type '<PS_ReadTransData_srv-response>"
  "N_Robot/PS_ReadTransData_srvResponse")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'PS_ReadTransData_srv-response)))
  "Returns string type for a service object of type 'PS_ReadTransData_srv-response"
  "N_Robot/PS_ReadTransData_srvResponse")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<PS_ReadTransData_srv-response>)))
  "Returns md5sum for a message object of type '<PS_ReadTransData_srv-response>"
  "abaef58b7907806e78b13d105be847a3")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'PS_ReadTransData_srv-response)))
  "Returns md5sum for a message object of type 'PS_ReadTransData_srv-response"
  "abaef58b7907806e78b13d105be847a3")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<PS_ReadTransData_srv-response>)))
  "Returns full string definition for message of type '<PS_ReadTransData_srv-response>"
  (cl:format cl:nil "int32  s32ErrCode~%string strErrInfo~%uint16 u16BattVolt~%int16  s16BattCurr~%int16  s16BattChargeCurr~%uint8  u8Temperture~%~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'PS_ReadTransData_srv-response)))
  "Returns full string definition for message of type 'PS_ReadTransData_srv-response"
  (cl:format cl:nil "int32  s32ErrCode~%string strErrInfo~%uint16 u16BattVolt~%int16  s16BattCurr~%int16  s16BattChargeCurr~%uint8  u8Temperture~%~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <PS_ReadTransData_srv-response>))
  (cl:+ 0
     4
     4 (cl:length (cl:slot-value msg 'strErrInfo))
     2
     2
     2
     1
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <PS_ReadTransData_srv-response>))
  "Converts a ROS message object to a list"
  (cl:list 'PS_ReadTransData_srv-response
    (cl:cons ':s32ErrCode (s32ErrCode msg))
    (cl:cons ':strErrInfo (strErrInfo msg))
    (cl:cons ':u16BattVolt (u16BattVolt msg))
    (cl:cons ':s16BattCurr (s16BattCurr msg))
    (cl:cons ':s16BattChargeCurr (s16BattChargeCurr msg))
    (cl:cons ':u8Temperture (u8Temperture msg))
))
(cl:defmethod roslisp-msg-protocol:service-request-type ((msg (cl:eql 'PS_ReadTransData_srv)))
  'PS_ReadTransData_srv-request)
(cl:defmethod roslisp-msg-protocol:service-response-type ((msg (cl:eql 'PS_ReadTransData_srv)))
  'PS_ReadTransData_srv-response)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'PS_ReadTransData_srv)))
  "Returns string type for a service object of type '<PS_ReadTransData_srv>"
  "N_Robot/PS_ReadTransData_srv")