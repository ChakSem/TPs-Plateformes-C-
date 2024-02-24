QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    src/main/c++/fr/univtours/polytech/FrameworkQT/controller/controller.cpp \
    src/main/c++/fr/univtours/polytech/FrameworkQT/main.cpp \
    src/main/c++/fr/univtours/polytech/FrameworkQT/model/Administrator.cpp \
    src/main/c++/fr/univtours/polytech/FrameworkQT/model/Profile.cpp \
    src/main/c++/fr/univtours/polytech/FrameworkQT/model/User.cpp \
    src/main/c++/fr/univtours/polytech/FrameworkQT/model/data.cpp \
    src/main/c++/fr/univtours/polytech/FrameworkQT/parseurJson/CparserJson.cpp \
    src/main/c++/fr/univtours/polytech/FrameworkQT/utils/encryption.cpp \
    src/main/c++/fr/univtours/polytech/FrameworkQT/utils/exception.cpp \
    src/main/c++/fr/univtours/polytech/FrameworkQT/view/addprofileinterface.cpp \
    src/main/c++/fr/univtours/polytech/FrameworkQT/view/backbutton.cpp \
    src/main/c++/fr/univtours/polytech/FrameworkQT/view/connectioninterface.cpp \
    src/main/c++/fr/univtours/polytech/FrameworkQT/view/creationuserinterface.cpp \
    src/main/c++/fr/univtours/polytech/FrameworkQT/view/deconnectioninterface.cpp \
    src/main/c++/fr/univtours/polytech/FrameworkQT/view/dialogerror.cpp \
    src/main/c++/fr/univtours/polytech/FrameworkQT/view/dialogvalidation.cpp \
    src/main/c++/fr/univtours/polytech/FrameworkQT/view/firstuserinscription.cpp \
    src/main/c++/fr/univtours/polytech/FrameworkQT/view/homeadmininterface.cpp \
    src/main/c++/fr/univtours/polytech/FrameworkQT/view/homeuserinterface.cpp \
    src/main/c++/fr/univtours/polytech/FrameworkQT/view/indexbdd.cpp \
    src/main/c++/fr/univtours/polytech/FrameworkQT/view/mainwindow.cpp \
    src/main/c++/fr/univtours/polytech/FrameworkQT/view/popup.cpp \
    src/main/c++/fr/univtours/polytech/FrameworkQT/view/profilesinterface.cpp \
    src/main/c++/fr/univtours/polytech/FrameworkQT/view/usermanagementinterface.cpp

HEADERS += \
    src/main/c++/fr/univtours/polytech/FrameworkQT/controller/controller.h \
    src/main/c++/fr/univtours/polytech/FrameworkQT/model/Administrator.h \
    src/main/c++/fr/univtours/polytech/FrameworkQT/model/Profile.h \
    src/main/c++/fr/univtours/polytech/FrameworkQT/model/Rights.h \
    src/main/c++/fr/univtours/polytech/FrameworkQT/model/UUID.h \
    src/main/c++/fr/univtours/polytech/FrameworkQT/model/User.h \
    src/main/c++/fr/univtours/polytech/FrameworkQT/model/data.h \
    src/main/c++/fr/univtours/polytech/FrameworkQT/parseurJson/CparserJson.h \
    src/main/c++/fr/univtours/polytech/FrameworkQT/parseurJson/nlohmann/adl_serializer.hpp \
    src/main/c++/fr/univtours/polytech/FrameworkQT/parseurJson/nlohmann/byte_container_with_subtype.hpp \
    src/main/c++/fr/univtours/polytech/FrameworkQT/parseurJson/nlohmann/detail/abi_macros.hpp \
    src/main/c++/fr/univtours/polytech/FrameworkQT/parseurJson/nlohmann/detail/conversions/from_json.hpp \
    src/main/c++/fr/univtours/polytech/FrameworkQT/parseurJson/nlohmann/detail/conversions/to_chars.hpp \
    src/main/c++/fr/univtours/polytech/FrameworkQT/parseurJson/nlohmann/detail/conversions/to_json.hpp \
    src/main/c++/fr/univtours/polytech/FrameworkQT/parseurJson/nlohmann/detail/exceptions.hpp \
    src/main/c++/fr/univtours/polytech/FrameworkQT/parseurJson/nlohmann/detail/hash.hpp \
    src/main/c++/fr/univtours/polytech/FrameworkQT/parseurJson/nlohmann/detail/input/binary_reader.hpp \
    src/main/c++/fr/univtours/polytech/FrameworkQT/parseurJson/nlohmann/detail/input/input_adapters.hpp \
    src/main/c++/fr/univtours/polytech/FrameworkQT/parseurJson/nlohmann/detail/input/json_sax.hpp \
    src/main/c++/fr/univtours/polytech/FrameworkQT/parseurJson/nlohmann/detail/input/lexer.hpp \
    src/main/c++/fr/univtours/polytech/FrameworkQT/parseurJson/nlohmann/detail/input/parser.hpp \
    src/main/c++/fr/univtours/polytech/FrameworkQT/parseurJson/nlohmann/detail/input/position_t.hpp \
    src/main/c++/fr/univtours/polytech/FrameworkQT/parseurJson/nlohmann/detail/iterators/internal_iterator.hpp \
    src/main/c++/fr/univtours/polytech/FrameworkQT/parseurJson/nlohmann/detail/iterators/iter_impl.hpp \
    src/main/c++/fr/univtours/polytech/FrameworkQT/parseurJson/nlohmann/detail/iterators/iteration_proxy.hpp \
    src/main/c++/fr/univtours/polytech/FrameworkQT/parseurJson/nlohmann/detail/iterators/iterator_traits.hpp \
    src/main/c++/fr/univtours/polytech/FrameworkQT/parseurJson/nlohmann/detail/iterators/json_reverse_iterator.hpp \
    src/main/c++/fr/univtours/polytech/FrameworkQT/parseurJson/nlohmann/detail/iterators/primitive_iterator.hpp \
    src/main/c++/fr/univtours/polytech/FrameworkQT/parseurJson/nlohmann/detail/json_custom_base_class.hpp \
    src/main/c++/fr/univtours/polytech/FrameworkQT/parseurJson/nlohmann/detail/json_pointer.hpp \
    src/main/c++/fr/univtours/polytech/FrameworkQT/parseurJson/nlohmann/detail/json_ref.hpp \
    src/main/c++/fr/univtours/polytech/FrameworkQT/parseurJson/nlohmann/detail/macro_scope.hpp \
    src/main/c++/fr/univtours/polytech/FrameworkQT/parseurJson/nlohmann/detail/macro_unscope.hpp \
    src/main/c++/fr/univtours/polytech/FrameworkQT/parseurJson/nlohmann/detail/meta/call_std/begin.hpp \
    src/main/c++/fr/univtours/polytech/FrameworkQT/parseurJson/nlohmann/detail/meta/call_std/end.hpp \
    src/main/c++/fr/univtours/polytech/FrameworkQT/parseurJson/nlohmann/detail/meta/cpp_future.hpp \
    src/main/c++/fr/univtours/polytech/FrameworkQT/parseurJson/nlohmann/detail/meta/detected.hpp \
    src/main/c++/fr/univtours/polytech/FrameworkQT/parseurJson/nlohmann/detail/meta/identity_tag.hpp \
    src/main/c++/fr/univtours/polytech/FrameworkQT/parseurJson/nlohmann/detail/meta/is_sax.hpp \
    src/main/c++/fr/univtours/polytech/FrameworkQT/parseurJson/nlohmann/detail/meta/std_fs.hpp \
    src/main/c++/fr/univtours/polytech/FrameworkQT/parseurJson/nlohmann/detail/meta/type_traits.hpp \
    src/main/c++/fr/univtours/polytech/FrameworkQT/parseurJson/nlohmann/detail/meta/void_t.hpp \
    src/main/c++/fr/univtours/polytech/FrameworkQT/parseurJson/nlohmann/detail/output/binary_writer.hpp \
    src/main/c++/fr/univtours/polytech/FrameworkQT/parseurJson/nlohmann/detail/output/output_adapters.hpp \
    src/main/c++/fr/univtours/polytech/FrameworkQT/parseurJson/nlohmann/detail/output/serializer.hpp \
    src/main/c++/fr/univtours/polytech/FrameworkQT/parseurJson/nlohmann/detail/string_concat.hpp \
    src/main/c++/fr/univtours/polytech/FrameworkQT/parseurJson/nlohmann/detail/string_escape.hpp \
    src/main/c++/fr/univtours/polytech/FrameworkQT/parseurJson/nlohmann/detail/value_t.hpp \
    src/main/c++/fr/univtours/polytech/FrameworkQT/parseurJson/nlohmann/json.hpp \
    src/main/c++/fr/univtours/polytech/FrameworkQT/parseurJson/nlohmann/json_fwd.hpp \
    src/main/c++/fr/univtours/polytech/FrameworkQT/parseurJson/nlohmann/ordered_map.hpp \
    src/main/c++/fr/univtours/polytech/FrameworkQT/parseurJson/nlohmann/thirdparty/hedley/hedley.hpp \
    src/main/c++/fr/univtours/polytech/FrameworkQT/parseurJson/nlohmann/thirdparty/hedley/hedley_undef.hpp \
    src/main/c++/fr/univtours/polytech/FrameworkQT/utils/encryption.h \
    src/main/c++/fr/univtours/polytech/FrameworkQT/utils/exception.h \
    src/main/c++/fr/univtours/polytech/FrameworkQT/view/addprofileinterface.h \
    src/main/c++/fr/univtours/polytech/FrameworkQT/view/backbutton.h \
    src/main/c++/fr/univtours/polytech/FrameworkQT/view/connectioninterface.h \
    src/main/c++/fr/univtours/polytech/FrameworkQT/view/creationuserinterface.h \
    src/main/c++/fr/univtours/polytech/FrameworkQT/view/deconnectioninterface.h \
    src/main/c++/fr/univtours/polytech/FrameworkQT/view/dialogerror.h \
    src/main/c++/fr/univtours/polytech/FrameworkQT/view/dialogvalidation.h \
    src/main/c++/fr/univtours/polytech/FrameworkQT/view/firstuserinscription.h \
    src/main/c++/fr/univtours/polytech/FrameworkQT/view/homeadmininterface.h \
    src/main/c++/fr/univtours/polytech/FrameworkQT/view/homeuserinterface.h \
    src/main/c++/fr/univtours/polytech/FrameworkQT/view/indexbdd.h \
    src/main/c++/fr/univtours/polytech/FrameworkQT/view/mainwindow.h \
    src/main/c++/fr/univtours/polytech/FrameworkQT/view/popup.h \
    src/main/c++/fr/univtours/polytech/FrameworkQT/view/profilesinterface.h \
    src/main/c++/fr/univtours/polytech/FrameworkQT/view/usermanagementinterface.h
    QT+=widgets
    QT+=core
    QT+=gui

FORMS += \
    src/main/c++/fr/univtours/polytech/FrameworkQT/view/BROUILLONmyaccount.ui \
    src/main/c++/fr/univtours/polytech/FrameworkQT/view/addprofileinterface.ui \
    src/main/c++/fr/univtours/polytech/FrameworkQT/view/backbutton.ui \
    src/main/c++/fr/univtours/polytech/FrameworkQT/view/connectioninterface.ui \
    src/main/c++/fr/univtours/polytech/FrameworkQT/view/creationuserinterface.ui \
    src/main/c++/fr/univtours/polytech/FrameworkQT/view/deconnectioninterface.ui \
    src/main/c++/fr/univtours/polytech/FrameworkQT/view/dialogerror.ui \
    src/main/c++/fr/univtours/polytech/FrameworkQT/view/dialogvalidation.ui \
    src/main/c++/fr/univtours/polytech/FrameworkQT/view/firstuserinscription.ui \
    src/main/c++/fr/univtours/polytech/FrameworkQT/view/homeadmininterface.ui \
    src/main/c++/fr/univtours/polytech/FrameworkQT/view/homeuserinterface.ui \
    src/main/c++/fr/univtours/polytech/FrameworkQT/view/indexbdd.ui \
    src/main/c++/fr/univtours/polytech/FrameworkQT/view/mainwindow.ui \
    src/main/c++/fr/univtours/polytech/FrameworkQT/view/profilesinterface.ui \
    src/main/c++/fr/univtours/polytech/FrameworkQT/view/usermanagementinterface.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

DISTFILES += \
    .gitignore \
    .vscode/settings.json \
    glog/uml/Choix.md \
    glog/uml/PUML.md \
    glog/uml/Rapport_TP8_1.md \
    glog/uml/TO_DO.md \
    src/main/c++/fr/univtours/polytech/FrameworkQT/data/admins.json \
    src/main/c++/fr/univtours/polytech/FrameworkQT/data/users.json \
    src/main/c++/fr/univtours/polytech/FrameworkQT/parseurJson/Adminstateur.json \
    src/main/c++/fr/univtours/polytech/FrameworkQT/parseurJson/ProfilUser.json \
    src/main/c++/fr/univtours/polytech/FrameworkQT/parseurJson/Utilsateur.json

RESOURCES += \
    forest-background.qrc
