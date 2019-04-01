
(cl:in-package :asdf)

(defsystem "N_Robot-msg"
  :depends-on (:roslisp-msg-protocol :roslisp-utils )
  :components ((:file "_package")
    (:file "PathFinder_msg" :depends-on ("_package_PathFinder_msg"))
    (:file "_package_PathFinder_msg" :depends-on ("_package"))
    (:file "Localization_msg" :depends-on ("_package_Localization_msg"))
    (:file "_package_Localization_msg" :depends-on ("_package"))
    (:file "CyberJoy_msg" :depends-on ("_package_CyberJoy_msg"))
    (:file "_package_CyberJoy_msg" :depends-on ("_package"))
  ))