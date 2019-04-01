; Auto-generated. Do not edit!


(cl:in-package N_Robot-msg)


;//! \htmlinclude Localization_msg.msg.html

(cl:defclass <Localization_msg> (roslisp-msg-protocol:ros-message)
  ((dMaxWeight
    :reader dMaxWeight
    :initarg :dMaxWeight
    :type cl:float
    :initform 0.0))
)

(cl:defclass Localization_msg (<Localization_msg>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <Localization_msg>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'Localization_msg)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name N_Robot-msg:<Localization_msg> is deprecated: use N_Robot-msg:Localization_msg instead.")))

(cl:ensure-generic-function 'dMaxWeight-val :lambda-list '(m))
(cl:defmethod dMaxWeight-val ((m <Localization_msg>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader N_Robot-msg:dMaxWeight-val is deprecated.  Use N_Robot-msg:dMaxWeight instead.")
  (dMaxWeight m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <Localization_msg>) ostream)
  "Serializes a message object of type '<Localization_msg>"
  (cl:let ((bits (roslisp-utils:encode-double-float-bits (cl:slot-value msg 'dMaxWeight))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 32) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 40) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 48) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 56) bits) ostream))
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <Localization_msg>) istream)
  "Deserializes a message object of type '<Localization_msg>"
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 32) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 40) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 48) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 56) bits) (cl:read-byte istream))
    (cl:setf (cl:slot-value msg 'dMaxWeight) (roslisp-utils:decode-double-float-bits bits)))
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<Localization_msg>)))
  "Returns string type for a message object of type '<Localization_msg>"
  "N_Robot/Localization_msg")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'Localization_msg)))
  "Returns string type for a message object of type 'Localization_msg"
  "N_Robot/Localization_msg")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<Localization_msg>)))
  "Returns md5sum for a message object of type '<Localization_msg>"
  "0dd53bf4fd6c6d6dbeb91b37b927cabd")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'Localization_msg)))
  "Returns md5sum for a message object of type 'Localization_msg"
  "0dd53bf4fd6c6d6dbeb91b37b927cabd")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<Localization_msg>)))
  "Returns full string definition for message of type '<Localization_msg>"
  (cl:format cl:nil "#Localization info~%float64 dMaxWeight~%~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'Localization_msg)))
  "Returns full string definition for message of type 'Localization_msg"
  (cl:format cl:nil "#Localization info~%float64 dMaxWeight~%~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <Localization_msg>))
  (cl:+ 0
     8
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <Localization_msg>))
  "Converts a ROS message object to a list"
  (cl:list 'Localization_msg
    (cl:cons ':dMaxWeight (dMaxWeight msg))
))
