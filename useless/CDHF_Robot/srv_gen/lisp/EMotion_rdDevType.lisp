; Auto-generated. Do not edit!


(cl:in-package CDHF_Robot-srv)


;//! \htmlinclude EMotion_rdDevType-request.msg.html

(cl:defclass <EMotion_rdDevType-request> (roslisp-msg-protocol:ros-message)
  ()
)

(cl:defclass EMotion_rdDevType-request (<EMotion_rdDevType-request>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <EMotion_rdDevType-request>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'EMotion_rdDevType-request)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name CDHF_Robot-srv:<EMotion_rdDevType-request> is deprecated: use CDHF_Robot-srv:EMotion_rdDevType-request instead.")))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <EMotion_rdDevType-request>) ostream)
  "Serializes a message object of type '<EMotion_rdDevType-request>"
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <EMotion_rdDevType-request>) istream)
  "Deserializes a message object of type '<EMotion_rdDevType-request>"
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<EMotion_rdDevType-request>)))
  "Returns string type for a service object of type '<EMotion_rdDevType-request>"
  "CDHF_Robot/EMotion_rdDevTypeRequest")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'EMotion_rdDevType-request)))
  "Returns string type for a service object of type 'EMotion_rdDevType-request"
  "CDHF_Robot/EMotion_rdDevTypeRequest")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<EMotion_rdDevType-request>)))
  "Returns md5sum for a message object of type '<EMotion_rdDevType-request>"
  "1a56c2ab9c7c9a056a5b3f503f5a4eff")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'EMotion_rdDevType-request)))
  "Returns md5sum for a message object of type 'EMotion_rdDevType-request"
  "1a56c2ab9c7c9a056a5b3f503f5a4eff")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<EMotion_rdDevType-request>)))
  "Returns full string definition for message of type '<EMotion_rdDevType-request>"
  (cl:format cl:nil "~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'EMotion_rdDevType-request)))
  "Returns full string definition for message of type 'EMotion_rdDevType-request"
  (cl:format cl:nil "~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <EMotion_rdDevType-request>))
  (cl:+ 0
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <EMotion_rdDevType-request>))
  "Converts a ROS message object to a list"
  (cl:list 'EMotion_rdDevType-request
))
;//! \htmlinclude EMotion_rdDevType-response.msg.html

(cl:defclass <EMotion_rdDevType-response> (roslisp-msg-protocol:ros-message)
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

(cl:defclass EMotion_rdDevType-response (<EMotion_rdDevType-response>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <EMotion_rdDevType-response>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'EMotion_rdDevType-response)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name CDHF_Robot-srv:<EMotion_rdDevType-response> is deprecated: use CDHF_Robot-srv:EMotion_rdDevType-response instead.")))

(cl:ensure-generic-function 'u8DevAddr-val :lambda-list '(m))
(cl:defmethod u8DevAddr-val ((m <EMotion_rdDevType-response>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader CDHF_Robot-srv:u8DevAddr-val is deprecated.  Use CDHF_Robot-srv:u8DevAddr instead.")
  (u8DevAddr m))

(cl:ensure-generic-function 'u8DevType-val :lambda-list '(m))
(cl:defmethod u8DevType-val ((m <EMotion_rdDevType-response>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader CDHF_Robot-srv:u8DevType-val is deprecated.  Use CDHF_Robot-srv:u8DevType instead.")
  (u8DevType m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <EMotion_rdDevType-response>) ostream)
  "Serializes a message object of type '<EMotion_rdDevType-response>"
  (cl:write-byte (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'u8DevAddr)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'u8DevType)) ostream)
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <EMotion_rdDevType-response>) istream)
  "Deserializes a message object of type '<EMotion_rdDevType-response>"
    (cl:setf (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'u8DevAddr)) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'u8DevType)) (cl:read-byte istream))
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<EMotion_rdDevType-response>)))
  "Returns string type for a service object of type '<EMotion_rdDevType-response>"
  "CDHF_Robot/EMotion_rdDevTypeResponse")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'EMotion_rdDevType-response)))
  "Returns string type for a service object of type 'EMotion_rdDevType-response"
  "CDHF_Robot/EMotion_rdDevTypeResponse")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<EMotion_rdDevType-response>)))
  "Returns md5sum for a message object of type '<EMotion_rdDevType-response>"
  "1a56c2ab9c7c9a056a5b3f503f5a4eff")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'EMotion_rdDevType-response)))
  "Returns md5sum for a message object of type 'EMotion_rdDevType-response"
  "1a56c2ab9c7c9a056a5b3f503f5a4eff")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<EMotion_rdDevType-response>)))
  "Returns full string definition for message of type '<EMotion_rdDevType-response>"
  (cl:format cl:nil "uint8 u8DevAddr~%uint8 u8DevType~%~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'EMotion_rdDevType-response)))
  "Returns full string definition for message of type 'EMotion_rdDevType-response"
  (cl:format cl:nil "uint8 u8DevAddr~%uint8 u8DevType~%~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <EMotion_rdDevType-response>))
  (cl:+ 0
     1
     1
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <EMotion_rdDevType-response>))
  "Converts a ROS message object to a list"
  (cl:list 'EMotion_rdDevType-response
    (cl:cons ':u8DevAddr (u8DevAddr msg))
    (cl:cons ':u8DevType (u8DevType msg))
))
(cl:defmethod roslisp-msg-protocol:service-request-type ((msg (cl:eql 'EMotion_rdDevType)))
  'EMotion_rdDevType-request)
(cl:defmethod roslisp-msg-protocol:service-response-type ((msg (cl:eql 'EMotion_rdDevType)))
  'EMotion_rdDevType-response)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'EMotion_rdDevType)))
  "Returns string type for a service object of type '<EMotion_rdDevType>"
  "CDHF_Robot/EMotion_rdDevType")