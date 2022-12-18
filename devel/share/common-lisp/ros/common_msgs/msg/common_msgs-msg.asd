
(cl:in-package :asdf)

(defsystem "common_msgs-msg"
  :depends-on (:roslisp-msg-protocol :roslisp-utils :std_msgs-msg
)
  :components ((:file "_package")
    (:file "ChassisStatus" :depends-on ("_package_ChassisStatus"))
    (:file "_package_ChassisStatus" :depends-on ("_package"))
    (:file "VehicleDynamicState" :depends-on ("_package_VehicleDynamicState"))
    (:file "_package_VehicleDynamicState" :depends-on ("_package"))
  ))