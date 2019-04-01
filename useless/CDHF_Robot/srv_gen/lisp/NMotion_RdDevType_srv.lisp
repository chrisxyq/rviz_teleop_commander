; Auto-generated. Do not edit!


(cl:in-package CDHF_Robot-srv)


;//! \htmlinclude NMotion_RdDevType_srv-request.msg.html

(cl:defclass <NMotion_RdDevType_srv-request> (roslisp-msg-protocol:ros-message)
  ()
)

(cl:defclass NMotion_RdDevType_srv-request (<NMotion_RdDevType_srv-request>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <NMotion_RdDevType_srv-request>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'NMotion_RdDevType_srv-request)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name CDHF_Robot-srv:<NMotion_RdDevType_srv-request> is deprecated: use CDHF_Robot-srv:NMotion_RdDevType_srv-request instead.")))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <NMotion_RdDevType_srv-request>) ostream)
  "Serializes a message object of type '<NMotion_RdDevType_srv-request>"
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <NMotion_RdDevType_srv-request>) istream)
  "Deserializes a message object of type '<NMotion_RdDevType_srv-request>"
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<NMotion_RdDevType_srv-request>)))
  "Returns string type for a service object of type '<NMotion_RdDevType_srv-request>"
  "CDHF_Robot/NMotion_RdDevType_srvRequest")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'NMotion_RdDevType_srv-request)))
  "Returns string type for a service object of type 'NMotion_RdDevType_srv-request"
  "CDHF_Robot/NMotion_RdDevType_srvRequest")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<NMotion_RdDevType_srv-request>)))
  "Returns md5sum for a message object of type '<NMotion_RdDevType_srv-request>"
  "1a56c2ab9c7c9a056a5b3f503f5a4eff")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'NMotion_RdDevType_srv-request)))
  "Returns md5sum for a message object of type 'NMotion_RdDevType_srv-request"
  "1a56c2ab9c7c9a056a5b3f503f5a4eff")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<NMotion_RdDevType_srv-request>)))
  "Returns full string definition for message of type '<NMotion_RdDevType_srv-request>"
  (cl:format cl:nil "~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'NMotion_RdDevType_srv-request)))
  "Returns full string definition for message of type 'NMotion_RdDevType_srv-request"
  (cl:format cl:nil "~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <NMotion_RdDevType_srv-request>))
  (cl:+ 0
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <NMotion_RdDevType_srv-request>))
  "Converts a ROS message object to a list"
  (cl:list 'NMotion_RdDevType_srv-request
))
;//! \htmlinclude NMotion_RdDevType_srv-response.msg.html

(cl:defclass <NMotion_RdDevType_srv-response> (roslisp-msg-protocol:ros-message)
  ((u8DevAddr
    :reader u8DevAddr
    :initarg :u8DevAddr
    :type cl:fixnum
    :initform 0)
   (u8DevType
    :reader u8DevType
    :initarg :u8DevType
    :type cl:fixnum
    :initform 0))
)

(cl:defclass NMotion_RdDevType_srv-response (<NMotion_RdDevType_srv-response>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <NMotion_RdDevType_srv-response>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'NMotion_RdDevType_srv-response)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name CDHF_Robot-srv:<NMotion_RdDevType_srv-response> is deprecated: use CDHF_Robot-srv:NMotion_RdDevType_srv-response instead.")))

(cl:ensure-generic-function 'u8DevAddr-val :lambda-list '(m))
(cl:defmethod u8DevAddr-val ((m <NMotion_RdDevType_srv-response>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader CDHF_Robot-srv:u8DevAddr-val is deprecated.  Use CDHF_Robot-srv:u8DevAddr instead.")
  (u8DevAddr m))

(cl:ensure-generic-function 'u8DevType-val :lambda-list '(m))
(cl:defmethod u8DevType-val ((m <NMotion_RdDevType_srv-response>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader CDHF_Robot-srv:u8DevType-val is deprecated.  Use CDHF_Robot-srv:u8DevType instead.")
  (u8DevType m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <NMotion_RdDevType_srv-response>) ostream)
  "Serializes a message object of type '<NMotion_RdDevType_srv-response>"
  (cl:write-byte (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'u8DevAddr)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'u8DevType)) ostream)
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <NMotion_RdDevType_srv-response>) istream)
  "Deserializes a message object of type '<NMotion_RdDevType_srv-response>"
    (cl:setf (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'u8DevAddr)) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'u8DevType)) (cl:read-byte istream))
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<NMotion_RdDevType_srv-response>)))
  "Returns string type for a service object of type '<NMotion_RdDevType_srv-response>"
  "CDHF_Robot/NMotion_RdDevType_srvResponse")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'NMotion_RdDevType_srv-response)))
  "Returns string type for a service object of type 'NMotion_RdDevType_srv-response"
  "CDHF_Robot/NMotion_RdDevType_srvResponse")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<NMotion_RdDevType_srv-response>)))
  "Returns md5sum for a message object of type '<NMotion_RdDevType_srv-response>"
  "1a56c2ab9c7c9a056a5b3f503f5a4eff")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'NMotion_RdDevType_srv-response)))
  "Returns md5sum for a message object of type 'NMotion_RdDevType_srv-response"
  "1a56c2ab9c7c9a056a5b3f503f5a4eff")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<NMotion_RdDevType_srv-response>)))
  "Returns full string definition for message of type '<NMotion_RdDevType_srv-response>"
  (cl:format cl:nil "uint8 u8DevAddr~%uint8 u8DevType~%~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'NMotion_RdDevType_srv-response)))
  "Returns full string definition for message of type 'NMotion_RdDevType_srv-response"
  (cl:format cl:nil "uint8 u8DevAddr~%uint8 u8DevType~%~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <NMotion_RdDevType_srv-response>))
  (cl:+ 0
     1
     1
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <NMotion_RdDevType_srv-response>))
  "Converts a ROS message object to a list"
  (cl:list 'NMotion_RdDevType_srv-response
    (cl:cons ':u8DevAddr (u8DevAddr msg))
    (cl:cons ':u8DevType (u8DevType msg))
))
(cl:defmethod roslisp-msg-protocol:service-request-type ((msg (cl:eql 'NMotion_RdDevType_srv)))
  'NMotion_RdDevType_srv-request)
(cl:defmethod roslisp-msg-protocol:service-response-type ((msg (cl:eql 'NMotion_RdDevType_srv)))
  'NMotion_RdDevType_srv-response)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'NMotion_RdDevType_srv)))
  "Returns string type for a service object of type '<NMotion_RdDevType_srv>"
  "CDHF_Robot/NMotion_RdDevType_srv")