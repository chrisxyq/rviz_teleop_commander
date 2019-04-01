; Auto-generated. Do not edit!


(cl:in-package N_Robot-msg)


;//! \htmlinclude PathFinder_msg.msg.html

(cl:defclass <PathFinder_msg> (roslisp-msg-protocol:ros-message)
  ((bValid
    :reader bValid
    :initarg :bValid
    :type cl:boolean
    :initform cl:nil)
   (i16JOY1X
    :reader i16JOY1X
    :initarg :i16JOY1X
    :type cl:fixnum
    :initform 0)
   (i16JOY1Y
    :reader i16JOY1Y
    :initarg :i16JOY1Y
    :type cl:fixnum
    :initform 0)
   (i16JOY1Z
    :reader i16JOY1Z
    :initarg :i16JOY1Z
    :type cl:fixnum
    :initform 0)
   (i16JOY2X
    :reader i16JOY2X
    :initarg :i16JOY2X
    :type cl:fixnum
    :initform 0)
   (i16JOY2Y
    :reader i16JOY2Y
    :initarg :i16JOY2Y
    :type cl:fixnum
    :initform 0)
   (i16JOY3X
    :reader i16JOY3X
    :initarg :i16JOY3X
    :type cl:fixnum
    :initform 0)
   (i16JOY3Y
    :reader i16JOY3Y
    :initarg :i16JOY3Y
    :type cl:fixnum
    :initform 0)
   (u16POTA
    :reader u16POTA
    :initarg :u16POTA
    :type cl:fixnum
    :initform 0)
   (u16POTB
    :reader u16POTB
    :initarg :u16POTB
    :type cl:fixnum
    :initform 0)
   (u8BAND
    :reader u8BAND
    :initarg :u8BAND
    :type cl:fixnum
    :initform 0)
   (i8ENCA
    :reader i8ENCA
    :initarg :i8ENCA
    :type cl:fixnum
    :initform 0)
   (i8ENCB
    :reader i8ENCB
    :initarg :i8ENCB
    :type cl:fixnum
    :initform 0)
   (u16Button
    :reader u16Button
    :initarg :u16Button
    :type cl:fixnum
    :initform 0))
)

(cl:defclass PathFinder_msg (<PathFinder_msg>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <PathFinder_msg>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'PathFinder_msg)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name N_Robot-msg:<PathFinder_msg> is deprecated: use N_Robot-msg:PathFinder_msg instead.")))

(cl:ensure-generic-function 'bValid-val :lambda-list '(m))
(cl:defmethod bValid-val ((m <PathFinder_msg>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader N_Robot-msg:bValid-val is deprecated.  Use N_Robot-msg:bValid instead.")
  (bValid m))

(cl:ensure-generic-function 'i16JOY1X-val :lambda-list '(m))
(cl:defmethod i16JOY1X-val ((m <PathFinder_msg>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader N_Robot-msg:i16JOY1X-val is deprecated.  Use N_Robot-msg:i16JOY1X instead.")
  (i16JOY1X m))

(cl:ensure-generic-function 'i16JOY1Y-val :lambda-list '(m))
(cl:defmethod i16JOY1Y-val ((m <PathFinder_msg>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader N_Robot-msg:i16JOY1Y-val is deprecated.  Use N_Robot-msg:i16JOY1Y instead.")
  (i16JOY1Y m))

(cl:ensure-generic-function 'i16JOY1Z-val :lambda-list '(m))
(cl:defmethod i16JOY1Z-val ((m <PathFinder_msg>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader N_Robot-msg:i16JOY1Z-val is deprecated.  Use N_Robot-msg:i16JOY1Z instead.")
  (i16JOY1Z m))

(cl:ensure-generic-function 'i16JOY2X-val :lambda-list '(m))
(cl:defmethod i16JOY2X-val ((m <PathFinder_msg>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader N_Robot-msg:i16JOY2X-val is deprecated.  Use N_Robot-msg:i16JOY2X instead.")
  (i16JOY2X m))

(cl:ensure-generic-function 'i16JOY2Y-val :lambda-list '(m))
(cl:defmethod i16JOY2Y-val ((m <PathFinder_msg>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader N_Robot-msg:i16JOY2Y-val is deprecated.  Use N_Robot-msg:i16JOY2Y instead.")
  (i16JOY2Y m))

(cl:ensure-generic-function 'i16JOY3X-val :lambda-list '(m))
(cl:defmethod i16JOY3X-val ((m <PathFinder_msg>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader N_Robot-msg:i16JOY3X-val is deprecated.  Use N_Robot-msg:i16JOY3X instead.")
  (i16JOY3X m))

(cl:ensure-generic-function 'i16JOY3Y-val :lambda-list '(m))
(cl:defmethod i16JOY3Y-val ((m <PathFinder_msg>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader N_Robot-msg:i16JOY3Y-val is deprecated.  Use N_Robot-msg:i16JOY3Y instead.")
  (i16JOY3Y m))

(cl:ensure-generic-function 'u16POTA-val :lambda-list '(m))
(cl:defmethod u16POTA-val ((m <PathFinder_msg>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader N_Robot-msg:u16POTA-val is deprecated.  Use N_Robot-msg:u16POTA instead.")
  (u16POTA m))

(cl:ensure-generic-function 'u16POTB-val :lambda-list '(m))
(cl:defmethod u16POTB-val ((m <PathFinder_msg>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader N_Robot-msg:u16POTB-val is deprecated.  Use N_Robot-msg:u16POTB instead.")
  (u16POTB m))

(cl:ensure-generic-function 'u8BAND-val :lambda-list '(m))
(cl:defmethod u8BAND-val ((m <PathFinder_msg>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader N_Robot-msg:u8BAND-val is deprecated.  Use N_Robot-msg:u8BAND instead.")
  (u8BAND m))

(cl:ensure-generic-function 'i8ENCA-val :lambda-list '(m))
(cl:defmethod i8ENCA-val ((m <PathFinder_msg>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader N_Robot-msg:i8ENCA-val is deprecated.  Use N_Robot-msg:i8ENCA instead.")
  (i8ENCA m))

(cl:ensure-generic-function 'i8ENCB-val :lambda-list '(m))
(cl:defmethod i8ENCB-val ((m <PathFinder_msg>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader N_Robot-msg:i8ENCB-val is deprecated.  Use N_Robot-msg:i8ENCB instead.")
  (i8ENCB m))

(cl:ensure-generic-function 'u16Button-val :lambda-list '(m))
(cl:defmethod u16Button-val ((m <PathFinder_msg>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader N_Robot-msg:u16Button-val is deprecated.  Use N_Robot-msg:u16Button instead.")
  (u16Button m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <PathFinder_msg>) ostream)
  "Serializes a message object of type '<PathFinder_msg>"
  (cl:write-byte (cl:ldb (cl:byte 8 0) (cl:if (cl:slot-value msg 'bValid) 1 0)) ostream)
  (cl:let* ((signed (cl:slot-value msg 'i16JOY1X)) (unsigned (cl:if (cl:< signed 0) (cl:+ signed 65536) signed)))
    (cl:write-byte (cl:ldb (cl:byte 8 0) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) unsigned) ostream)
    )
  (cl:let* ((signed (cl:slot-value msg 'i16JOY1Y)) (unsigned (cl:if (cl:< signed 0) (cl:+ signed 65536) signed)))
    (cl:write-byte (cl:ldb (cl:byte 8 0) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) unsigned) ostream)
    )
  (cl:let* ((signed (cl:slot-value msg 'i16JOY1Z)) (unsigned (cl:if (cl:< signed 0) (cl:+ signed 65536) signed)))
    (cl:write-byte (cl:ldb (cl:byte 8 0) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) unsigned) ostream)
    )
  (cl:let* ((signed (cl:slot-value msg 'i16JOY2X)) (unsigned (cl:if (cl:< signed 0) (cl:+ signed 65536) signed)))
    (cl:write-byte (cl:ldb (cl:byte 8 0) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) unsigned) ostream)
    )
  (cl:let* ((signed (cl:slot-value msg 'i16JOY2Y)) (unsigned (cl:if (cl:< signed 0) (cl:+ signed 65536) signed)))
    (cl:write-byte (cl:ldb (cl:byte 8 0) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) unsigned) ostream)
    )
  (cl:let* ((signed (cl:slot-value msg 'i16JOY3X)) (unsigned (cl:if (cl:< signed 0) (cl:+ signed 65536) signed)))
    (cl:write-byte (cl:ldb (cl:byte 8 0) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) unsigned) ostream)
    )
  (cl:let* ((signed (cl:slot-value msg 'i16JOY3Y)) (unsigned (cl:if (cl:< signed 0) (cl:+ signed 65536) signed)))
    (cl:write-byte (cl:ldb (cl:byte 8 0) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) unsigned) ostream)
    )
  (cl:write-byte (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'u16POTA)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 8) (cl:slot-value msg 'u16POTA)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'u16POTB)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 8) (cl:slot-value msg 'u16POTB)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'u8BAND)) ostream)
  (cl:let* ((signed (cl:slot-value msg 'i8ENCA)) (unsigned (cl:if (cl:< signed 0) (cl:+ signed 256) signed)))
    (cl:write-byte (cl:ldb (cl:byte 8 0) unsigned) ostream)
    )
  (cl:let* ((signed (cl:slot-value msg 'i8ENCB)) (unsigned (cl:if (cl:< signed 0) (cl:+ signed 256) signed)))
    (cl:write-byte (cl:ldb (cl:byte 8 0) unsigned) ostream)
    )
  (cl:write-byte (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'u16Button)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 8) (cl:slot-value msg 'u16Button)) ostream)
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <PathFinder_msg>) istream)
  "Deserializes a message object of type '<PathFinder_msg>"
    (cl:setf (cl:slot-value msg 'bValid) (cl:not (cl:zerop (cl:read-byte istream))))
    (cl:let ((unsigned 0))
      (cl:setf (cl:ldb (cl:byte 8 0) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) unsigned) (cl:read-byte istream))
      (cl:setf (cl:slot-value msg 'i16JOY1X) (cl:if (cl:< unsigned 32768) unsigned (cl:- unsigned 65536))))
    (cl:let ((unsigned 0))
      (cl:setf (cl:ldb (cl:byte 8 0) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) unsigned) (cl:read-byte istream))
      (cl:setf (cl:slot-value msg 'i16JOY1Y) (cl:if (cl:< unsigned 32768) unsigned (cl:- unsigned 65536))))
    (cl:let ((unsigned 0))
      (cl:setf (cl:ldb (cl:byte 8 0) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) unsigned) (cl:read-byte istream))
      (cl:setf (cl:slot-value msg 'i16JOY1Z) (cl:if (cl:< unsigned 32768) unsigned (cl:- unsigned 65536))))
    (cl:let ((unsigned 0))
      (cl:setf (cl:ldb (cl:byte 8 0) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) unsigned) (cl:read-byte istream))
      (cl:setf (cl:slot-value msg 'i16JOY2X) (cl:if (cl:< unsigned 32768) unsigned (cl:- unsigned 65536))))
    (cl:let ((unsigned 0))
      (cl:setf (cl:ldb (cl:byte 8 0) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) unsigned) (cl:read-byte istream))
      (cl:setf (cl:slot-value msg 'i16JOY2Y) (cl:if (cl:< unsigned 32768) unsigned (cl:- unsigned 65536))))
    (cl:let ((unsigned 0))
      (cl:setf (cl:ldb (cl:byte 8 0) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) unsigned) (cl:read-byte istream))
      (cl:setf (cl:slot-value msg 'i16JOY3X) (cl:if (cl:< unsigned 32768) unsigned (cl:- unsigned 65536))))
    (cl:let ((unsigned 0))
      (cl:setf (cl:ldb (cl:byte 8 0) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) unsigned) (cl:read-byte istream))
      (cl:setf (cl:slot-value msg 'i16JOY3Y) (cl:if (cl:< unsigned 32768) unsigned (cl:- unsigned 65536))))
    (cl:setf (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'u16POTA)) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 8) (cl:slot-value msg 'u16POTA)) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'u16POTB)) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 8) (cl:slot-value msg 'u16POTB)) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'u8BAND)) (cl:read-byte istream))
    (cl:let ((unsigned 0))
      (cl:setf (cl:ldb (cl:byte 8 0) unsigned) (cl:read-byte istream))
      (cl:setf (cl:slot-value msg 'i8ENCA) (cl:if (cl:< unsigned 128) unsigned (cl:- unsigned 256))))
    (cl:let ((unsigned 0))
      (cl:setf (cl:ldb (cl:byte 8 0) unsigned) (cl:read-byte istream))
      (cl:setf (cl:slot-value msg 'i8ENCB) (cl:if (cl:< unsigned 128) unsigned (cl:- unsigned 256))))
    (cl:setf (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'u16Button)) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 8) (cl:slot-value msg 'u16Button)) (cl:read-byte istream))
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<PathFinder_msg>)))
  "Returns string type for a message object of type '<PathFinder_msg>"
  "N_Robot/PathFinder_msg")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'PathFinder_msg)))
  "Returns string type for a message object of type 'PathFinder_msg"
  "N_Robot/PathFinder_msg")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<PathFinder_msg>)))
  "Returns md5sum for a message object of type '<PathFinder_msg>"
  "a0b961ff8f78bdde7ce47c9a5aab32e2")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'PathFinder_msg)))
  "Returns md5sum for a message object of type 'PathFinder_msg"
  "a0b961ff8f78bdde7ce47c9a5aab32e2")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<PathFinder_msg>)))
  "Returns full string definition for message of type '<PathFinder_msg>"
  (cl:format cl:nil "#Remote CTRLR VALID BIT~%bool bValid~%#JOY1~%int16 i16JOY1X~%int16 i16JOY1Y~%int16 i16JOY1Z~%#JOY2~%int16 i16JOY2X~%int16 i16JOY2Y~%#JOY3~%int16 i16JOY3X~%int16 i16JOY3Y~%#POT A/B~%uint16 u16POTA~%uint16 u16POTB~%#BAND A/B~%uint8 u8BAND~%#ENC A/B~%int8 i8ENCA~%int8 i8ENCB~%#TOG & BUTTON~%uint16 u16Button~%~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'PathFinder_msg)))
  "Returns full string definition for message of type 'PathFinder_msg"
  (cl:format cl:nil "#Remote CTRLR VALID BIT~%bool bValid~%#JOY1~%int16 i16JOY1X~%int16 i16JOY1Y~%int16 i16JOY1Z~%#JOY2~%int16 i16JOY2X~%int16 i16JOY2Y~%#JOY3~%int16 i16JOY3X~%int16 i16JOY3Y~%#POT A/B~%uint16 u16POTA~%uint16 u16POTB~%#BAND A/B~%uint8 u8BAND~%#ENC A/B~%int8 i8ENCA~%int8 i8ENCB~%#TOG & BUTTON~%uint16 u16Button~%~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <PathFinder_msg>))
  (cl:+ 0
     1
     2
     2
     2
     2
     2
     2
     2
     2
     2
     1
     1
     1
     2
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <PathFinder_msg>))
  "Converts a ROS message object to a list"
  (cl:list 'PathFinder_msg
    (cl:cons ':bValid (bValid msg))
    (cl:cons ':i16JOY1X (i16JOY1X msg))
    (cl:cons ':i16JOY1Y (i16JOY1Y msg))
    (cl:cons ':i16JOY1Z (i16JOY1Z msg))
    (cl:cons ':i16JOY2X (i16JOY2X msg))
    (cl:cons ':i16JOY2Y (i16JOY2Y msg))
    (cl:cons ':i16JOY3X (i16JOY3X msg))
    (cl:cons ':i16JOY3Y (i16JOY3Y msg))
    (cl:cons ':u16POTA (u16POTA msg))
    (cl:cons ':u16POTB (u16POTB msg))
    (cl:cons ':u8BAND (u8BAND msg))
    (cl:cons ':i8ENCA (i8ENCA msg))
    (cl:cons ':i8ENCB (i8ENCB msg))
    (cl:cons ':u16Button (u16Button msg))
))
