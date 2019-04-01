; Auto-generated. Do not edit!


(cl:in-package N_Robot-msg)


;//! \htmlinclude CyberJoy_msg.msg.html

(cl:defclass <CyberJoy_msg> (roslisp-msg-protocol:ros-message)
  ((bValid
    :reader bValid
    :initarg :bValid
    :type cl:boolean
    :initform cl:nil)
   (i16VelY
    :reader i16VelY
    :initarg :i16VelY
    :type cl:fixnum
    :initform 0)
   (i16VelX
    :reader i16VelX
    :initarg :i16VelX
    :type cl:fixnum
    :initform 0)
   (i16VelR
    :reader i16VelR
    :initarg :i16VelR
    :type cl:fixnum
    :initform 0)
   (i16VelR2
    :reader i16VelR2
    :initarg :i16VelR2
    :type cl:fixnum
    :initform 0))
)

(cl:defclass CyberJoy_msg (<CyberJoy_msg>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <CyberJoy_msg>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'CyberJoy_msg)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name N_Robot-msg:<CyberJoy_msg> is deprecated: use N_Robot-msg:CyberJoy_msg instead.")))

(cl:ensure-generic-function 'bValid-val :lambda-list '(m))
(cl:defmethod bValid-val ((m <CyberJoy_msg>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader N_Robot-msg:bValid-val is deprecated.  Use N_Robot-msg:bValid instead.")
  (bValid m))

(cl:ensure-generic-function 'i16VelY-val :lambda-list '(m))
(cl:defmethod i16VelY-val ((m <CyberJoy_msg>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader N_Robot-msg:i16VelY-val is deprecated.  Use N_Robot-msg:i16VelY instead.")
  (i16VelY m))

(cl:ensure-generic-function 'i16VelX-val :lambda-list '(m))
(cl:defmethod i16VelX-val ((m <CyberJoy_msg>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader N_Robot-msg:i16VelX-val is deprecated.  Use N_Robot-msg:i16VelX instead.")
  (i16VelX m))

(cl:ensure-generic-function 'i16VelR-val :lambda-list '(m))
(cl:defmethod i16VelR-val ((m <CyberJoy_msg>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader N_Robot-msg:i16VelR-val is deprecated.  Use N_Robot-msg:i16VelR instead.")
  (i16VelR m))

(cl:ensure-generic-function 'i16VelR2-val :lambda-list '(m))
(cl:defmethod i16VelR2-val ((m <CyberJoy_msg>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader N_Robot-msg:i16VelR2-val is deprecated.  Use N_Robot-msg:i16VelR2 instead.")
  (i16VelR2 m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <CyberJoy_msg>) ostream)
  "Serializes a message object of type '<CyberJoy_msg>"
  (cl:write-byte (cl:ldb (cl:byte 8 0) (cl:if (cl:slot-value msg 'bValid) 1 0)) ostream)
  (cl:let* ((signed (cl:slot-value msg 'i16VelY)) (unsigned (cl:if (cl:< signed 0) (cl:+ signed 65536) signed)))
    (cl:write-byte (cl:ldb (cl:byte 8 0) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) unsigned) ostream)
    )
  (cl:let* ((signed (cl:slot-value msg 'i16VelX)) (unsigned (cl:if (cl:< signed 0) (cl:+ signed 65536) signed)))
    (cl:write-byte (cl:ldb (cl:byte 8 0) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) unsigned) ostream)
    )
  (cl:let* ((signed (cl:slot-value msg 'i16VelR)) (unsigned (cl:if (cl:< signed 0) (cl:+ signed 65536) signed)))
    (cl:write-byte (cl:ldb (cl:byte 8 0) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) unsigned) ostream)
    )
  (cl:let* ((signed (cl:slot-value msg 'i16VelR2)) (unsigned (cl:if (cl:< signed 0) (cl:+ signed 65536) signed)))
    (cl:write-byte (cl:ldb (cl:byte 8 0) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) unsigned) ostream)
    )
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <CyberJoy_msg>) istream)
  "Deserializes a message object of type '<CyberJoy_msg>"
    (cl:setf (cl:slot-value msg 'bValid) (cl:not (cl:zerop (cl:read-byte istream))))
    (cl:let ((unsigned 0))
      (cl:setf (cl:ldb (cl:byte 8 0) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) unsigned) (cl:read-byte istream))
      (cl:setf (cl:slot-value msg 'i16VelY) (cl:if (cl:< unsigned 32768) unsigned (cl:- unsigned 65536))))
    (cl:let ((unsigned 0))
      (cl:setf (cl:ldb (cl:byte 8 0) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) unsigned) (cl:read-byte istream))
      (cl:setf (cl:slot-value msg 'i16VelX) (cl:if (cl:< unsigned 32768) unsigned (cl:- unsigned 65536))))
    (cl:let ((unsigned 0))
      (cl:setf (cl:ldb (cl:byte 8 0) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) unsigned) (cl:read-byte istream))
      (cl:setf (cl:slot-value msg 'i16VelR) (cl:if (cl:< unsigned 32768) unsigned (cl:- unsigned 65536))))
    (cl:let ((unsigned 0))
      (cl:setf (cl:ldb (cl:byte 8 0) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) unsigned) (cl:read-byte istream))
      (cl:setf (cl:slot-value msg 'i16VelR2) (cl:if (cl:< unsigned 32768) unsigned (cl:- unsigned 65536))))
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<CyberJoy_msg>)))
  "Returns string type for a message object of type '<CyberJoy_msg>"
  "N_Robot/CyberJoy_msg")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'CyberJoy_msg)))
  "Returns string type for a message object of type 'CyberJoy_msg"
  "N_Robot/CyberJoy_msg")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<CyberJoy_msg>)))
  "Returns md5sum for a message object of type '<CyberJoy_msg>"
  "f0201e833065447e9b7599cb5c15e657")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'CyberJoy_msg)))
  "Returns md5sum for a message object of type 'CyberJoy_msg"
  "f0201e833065447e9b7599cb5c15e657")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<CyberJoy_msg>)))
  "Returns full string definition for message of type '<CyberJoy_msg>"
  (cl:format cl:nil "#Cyber Joy valid info~%bool bValid~%#Velocity info~%int16 i16VelY~%int16 i16VelX~%int16 i16VelR~%int16 i16VelR2~%~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'CyberJoy_msg)))
  "Returns full string definition for message of type 'CyberJoy_msg"
  (cl:format cl:nil "#Cyber Joy valid info~%bool bValid~%#Velocity info~%int16 i16VelY~%int16 i16VelX~%int16 i16VelR~%int16 i16VelR2~%~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <CyberJoy_msg>))
  (cl:+ 0
     1
     2
     2
     2
     2
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <CyberJoy_msg>))
  "Converts a ROS message object to a list"
  (cl:list 'CyberJoy_msg
    (cl:cons ':bValid (bValid msg))
    (cl:cons ':i16VelY (i16VelY msg))
    (cl:cons ':i16VelX (i16VelX msg))
    (cl:cons ':i16VelR (i16VelR msg))
    (cl:cons ':i16VelR2 (i16VelR2 msg))
))
