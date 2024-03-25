QT       += core gui
QT += sql
RC_ICONS =icone.ico

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets
CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    src/main/c++/fr/univtours/polytech/FrameworkQT/controller/controller.cpp \
    src/main/c++/fr/univtours/polytech/FrameworkQT/main.cpp \
    src/main/c++/fr/univtours/polytech/FrameworkQT/model/profile.cpp \
    src/main/c++/fr/univtours/polytech/FrameworkQT/model/user.cpp \
    src/main/c++/fr/univtours/polytech/FrameworkQT/model/data.cpp \
    src/main/c++/fr/univtours/polytech/FrameworkQT/parserJson/parserjson.cpp \
    src/main/c++/fr/univtours/polytech/FrameworkQT/parserSqlite/parsersqlite.cpp \
    src/main/c++/fr/univtours/polytech/FrameworkQT/utils/Qt-AES-master/qaesencryption.cpp \
    src/main/c++/fr/univtours/polytech/FrameworkQT/utils/encryption.cpp \
    src/main/c++/fr/univtours/polytech/FrameworkQT/utils/exception.cpp \
    src/main/c++/fr/univtours/polytech/FrameworkQT/view/accountinformationsinterface.cpp \
    src/main/c++/fr/univtours/polytech/FrameworkQT/view/addprofileinterface.cpp \
    src/main/c++/fr/univtours/polytech/FrameworkQT/view/backbutton.cpp \
    src/main/c++/fr/univtours/polytech/FrameworkQT/view/connectioninterface.cpp \
    src/main/c++/fr/univtours/polytech/FrameworkQT/view/creationuserinterface.cpp \
    src/main/c++/fr/univtours/polytech/FrameworkQT/view/databaseinterface.cpp \
    src/main/c++/fr/univtours/polytech/FrameworkQT/view/databasemanagementinterface.cpp \
    src/main/c++/fr/univtours/polytech/FrameworkQT/view/databasevisualisationinterface.cpp \
    src/main/c++/fr/univtours/polytech/FrameworkQT/view/deconnectioninterface.cpp \
    src/main/c++/fr/univtours/polytech/FrameworkQT/view/firstuserinscription.cpp \
    src/main/c++/fr/univtours/polytech/FrameworkQT/view/homeadmininterface.cpp \
    src/main/c++/fr/univtours/polytech/FrameworkQT/view/homeuserinterface.cpp \
    src/main/c++/fr/univtours/polytech/FrameworkQT/view/mainwindow.cpp \
    src/main/c++/fr/univtours/polytech/FrameworkQT/view/profilesinterface.cpp \
    src/main/c++/fr/univtours/polytech/FrameworkQT/view/usermanagementinterface.cpp

HEADERS += \
    src/main/c++/fr/univtours/polytech/FrameworkQT/controller/controller.h \
    src/main/c++/fr/univtours/polytech/FrameworkQT/model/profile.h \
    src/main/c++/fr/univtours/polytech/FrameworkQT/model/rights.h \
    src/main/c++/fr/univtours/polytech/FrameworkQT/model/uuid.h \
    src/main/c++/fr/univtours/polytech/FrameworkQT/model/user.h \
    src/main/c++/fr/univtours/polytech/FrameworkQT/model/data.h \
    src/main/c++/fr/univtours/polytech/FrameworkQT/parserJson/parserjson.h \
    src/main/c++/fr/univtours/polytech/FrameworkQT/parserJson/nlohmann/adl_serializer.hpp \
    src/main/c++/fr/univtours/polytech/FrameworkQT/parserJson/nlohmann/byte_container_with_subtype.hpp \
    src/main/c++/fr/univtours/polytech/FrameworkQT/parserJson/nlohmann/detail/abi_macros.hpp \
    src/main/c++/fr/univtours/polytech/FrameworkQT/parserJson/nlohmann/detail/conversions/from_json.hpp \
    src/main/c++/fr/univtours/polytech/FrameworkQT/parserJson/nlohmann/detail/conversions/to_chars.hpp \
    src/main/c++/fr/univtours/polytech/FrameworkQT/parserJson/nlohmann/detail/conversions/to_json.hpp \
    src/main/c++/fr/univtours/polytech/FrameworkQT/parserJson/nlohmann/detail/exceptions.hpp \
    src/main/c++/fr/univtours/polytech/FrameworkQT/parserJson/nlohmann/detail/hash.hpp \
    src/main/c++/fr/univtours/polytech/FrameworkQT/parserJson/nlohmann/detail/input/binary_reader.hpp \
    src/main/c++/fr/univtours/polytech/FrameworkQT/parserJson/nlohmann/detail/input/input_adapters.hpp \
    src/main/c++/fr/univtours/polytech/FrameworkQT/parserJson/nlohmann/detail/input/json_sax.hpp \
    src/main/c++/fr/univtours/polytech/FrameworkQT/parserJson/nlohmann/detail/input/lexer.hpp \
    src/main/c++/fr/univtours/polytech/FrameworkQT/parserJson/nlohmann/detail/input/parser.hpp \
    src/main/c++/fr/univtours/polytech/FrameworkQT/parserJson/nlohmann/detail/input/position_t.hpp \
    src/main/c++/fr/univtours/polytech/FrameworkQT/parserJson/nlohmann/detail/iterators/internal_iterator.hpp \
    src/main/c++/fr/univtours/polytech/FrameworkQT/parserJson/nlohmann/detail/iterators/iter_impl.hpp \
    src/main/c++/fr/univtours/polytech/FrameworkQT/parserJson/nlohmann/detail/iterators/iteration_proxy.hpp \
    src/main/c++/fr/univtours/polytech/FrameworkQT/parserJson/nlohmann/detail/iterators/iterator_traits.hpp \
    src/main/c++/fr/univtours/polytech/FrameworkQT/parserJson/nlohmann/detail/iterators/json_reverse_iterator.hpp \
    src/main/c++/fr/univtours/polytech/FrameworkQT/parserJson/nlohmann/detail/iterators/primitive_iterator.hpp \
    src/main/c++/fr/univtours/polytech/FrameworkQT/parserJson/nlohmann/detail/json_custom_base_class.hpp \
    src/main/c++/fr/univtours/polytech/FrameworkQT/parserJson/nlohmann/detail/json_pointer.hpp \
    src/main/c++/fr/univtours/polytech/FrameworkQT/parserJson/nlohmann/detail/json_ref.hpp \
    src/main/c++/fr/univtours/polytech/FrameworkQT/parserJson/nlohmann/detail/macro_scope.hpp \
    src/main/c++/fr/univtours/polytech/FrameworkQT/parserJson/nlohmann/detail/macro_unscope.hpp \
    src/main/c++/fr/univtours/polytech/FrameworkQT/parserJson/nlohmann/detail/meta/call_std/begin.hpp \
    src/main/c++/fr/univtours/polytech/FrameworkQT/parserJson/nlohmann/detail/meta/call_std/end.hpp \
    src/main/c++/fr/univtours/polytech/FrameworkQT/parserJson/nlohmann/detail/meta/cpp_future.hpp \
    src/main/c++/fr/univtours/polytech/FrameworkQT/parserJson/nlohmann/detail/meta/detected.hpp \
    src/main/c++/fr/univtours/polytech/FrameworkQT/parserJson/nlohmann/detail/meta/identity_tag.hpp \
    src/main/c++/fr/univtours/polytech/FrameworkQT/parserJson/nlohmann/detail/meta/is_sax.hpp \
    src/main/c++/fr/univtours/polytech/FrameworkQT/parserJson/nlohmann/detail/meta/std_fs.hpp \
    src/main/c++/fr/univtours/polytech/FrameworkQT/parserJson/nlohmann/detail/meta/type_traits.hpp \
    src/main/c++/fr/univtours/polytech/FrameworkQT/parserJson/nlohmann/detail/meta/void_t.hpp \
    src/main/c++/fr/univtours/polytech/FrameworkQT/parserJson/nlohmann/detail/output/binary_writer.hpp \
    src/main/c++/fr/univtours/polytech/FrameworkQT/parserJson/nlohmann/detail/output/output_adapters.hpp \
    src/main/c++/fr/univtours/polytech/FrameworkQT/parserJson/nlohmann/detail/output/serializer.hpp \
    src/main/c++/fr/univtours/polytech/FrameworkQT/parserJson/nlohmann/detail/string_concat.hpp \
    src/main/c++/fr/univtours/polytech/FrameworkQT/parserJson/nlohmann/detail/string_escape.hpp \
    src/main/c++/fr/univtours/polytech/FrameworkQT/parserJson/nlohmann/detail/value_t.hpp \
    src/main/c++/fr/univtours/polytech/FrameworkQT/parserJson/nlohmann/json.hpp \
    src/main/c++/fr/univtours/polytech/FrameworkQT/parserJson/nlohmann/json_fwd.hpp \
    src/main/c++/fr/univtours/polytech/FrameworkQT/parserJson/nlohmann/ordered_map.hpp \
    src/main/c++/fr/univtours/polytech/FrameworkQT/parserJson/nlohmann/thirdparty/hedley/hedley.hpp \
    src/main/c++/fr/univtours/polytech/FrameworkQT/parserJson/nlohmann/thirdparty/hedley/hedley_undef.hpp \
    src/main/c++/fr/univtours/polytech/FrameworkQT/parserSqlite/parsersqlite.h \
    src/main/c++/fr/univtours/polytech/FrameworkQT/utils/Qt-AES-master/aesni/aesni-enc-cbc.h \
    src/main/c++/fr/univtours/polytech/FrameworkQT/utils/Qt-AES-master/aesni/aesni-enc-ecb.h \
    src/main/c++/fr/univtours/polytech/FrameworkQT/utils/Qt-AES-master/aesni/aesni-key-exp.h \
    src/main/c++/fr/univtours/polytech/FrameworkQT/utils/Qt-AES-master/aesni/aesni-key-init.h \
    src/main/c++/fr/univtours/polytech/FrameworkQT/utils/Qt-AES-master/qaesencryption.h \
    src/main/c++/fr/univtours/polytech/FrameworkQT/utils/encryption.h \
    src/main/c++/fr/univtours/polytech/FrameworkQT/utils/exception.h \
    src/main/c++/fr/univtours/polytech/FrameworkQT/view/accountinformationsinterface.h \
    src/main/c++/fr/univtours/polytech/FrameworkQT/view/addprofileinterface.h \
    src/main/c++/fr/univtours/polytech/FrameworkQT/view/backbutton.h \
    src/main/c++/fr/univtours/polytech/FrameworkQT/view/connectioninterface.h \
    src/main/c++/fr/univtours/polytech/FrameworkQT/view/creationuserinterface.h \
    src/main/c++/fr/univtours/polytech/FrameworkQT/view/databaseinterface.h \
    src/main/c++/fr/univtours/polytech/FrameworkQT/view/databasemanagementinterface.h \
    src/main/c++/fr/univtours/polytech/FrameworkQT/view/databasevisualisationinterface.h \
    src/main/c++/fr/univtours/polytech/FrameworkQT/view/deconnectioninterface.h \
    src/main/c++/fr/univtours/polytech/FrameworkQT/view/firstuserinscription.h \
    src/main/c++/fr/univtours/polytech/FrameworkQT/view/homeadmininterface.h \
    src/main/c++/fr/univtours/polytech/FrameworkQT/view/homeuserinterface.h \
    src/main/c++/fr/univtours/polytech/FrameworkQT/view/mainwindow.h \
    src/main/c++/fr/univtours/polytech/FrameworkQT/view/profilesinterface.h \
    src/main/c++/fr/univtours/polytech/FrameworkQT/view/usermanagementinterface.h
    QT+=widgets
    QT+=core
    QT+=gui

FORMS += \
    src/main/c++/fr/univtours/polytech/FrameworkQT/view/accountinformationsinterface.ui \
    src/main/c++/fr/univtours/polytech/FrameworkQT/view/addprofileinterface.ui \
    src/main/c++/fr/univtours/polytech/FrameworkQT/view/backbutton.ui \
    src/main/c++/fr/univtours/polytech/FrameworkQT/view/connectioninterface.ui \
    src/main/c++/fr/univtours/polytech/FrameworkQT/view/creationuserinterface.ui \
    src/main/c++/fr/univtours/polytech/FrameworkQT/view/databaseinterface.ui \
    src/main/c++/fr/univtours/polytech/FrameworkQT/view/databasemanagementinterface.ui \
    src/main/c++/fr/univtours/polytech/FrameworkQT/view/databasevisualisationinterface.ui \
    src/main/c++/fr/univtours/polytech/FrameworkQT/view/deconnectioninterface.ui \
    src/main/c++/fr/univtours/polytech/FrameworkQT/view/firstuserinscription.ui \
    src/main/c++/fr/univtours/polytech/FrameworkQT/view/homeadmininterface.ui \
    src/main/c++/fr/univtours/polytech/FrameworkQT/view/homeuserinterface.ui \
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
    src/main/c++/fr/univtours/polytech/FrameworkQT/parserJson/Adminstateur.json \
    src/main/c++/fr/univtours/polytech/FrameworkQT/parserJson/ProfilUser.json \
    src/main/c++/fr/univtours/polytech/FrameworkQT/parserJson/Utilsateur.json \
    src/main/c++/fr/univtours/polytech/FrameworkQT/utils/Qt-AES-master/CMakeLists.txt \
    src/main/c++/fr/univtours/polytech/FrameworkQT/utils/Qt-AES-master/CONTRIBUTING.md \
    src/main/c++/fr/univtours/polytech/FrameworkQT/utils/Qt-AES-master/LICENSE \
    src/main/c++/fr/univtours/polytech/FrameworkQT/utils/Qt-AES-master/QtAESConfig.cmake.in \
    src/main/c++/fr/univtours/polytech/FrameworkQT/utils/Qt-AES-master/README.md \
    src/main/c++/fr/univtours/polytech/FrameworkQT/utils/Qt-AES-master/unit_test/alices-in-wonderland.txt \
    src/main/c++/fr/univtours/polytech/FrameworkQT/utils/Qt-AES-master/unit_test/la-divina-commedia.txt \
    src/main/c++/fr/univtours/polytech/FrameworkQT/utils/Qt-AES-master/unit_test/moby-dick.txt \
    src/main/c++/fr/univtours/polytech/FrameworkQT/utils/Qt-AES-master/unit_test/shakespeare-complete-works.txt

RESOURCES +=

SUBDIRS += \
    src/main/c++/fr/univtours/polytech/FrameworkQT/utils/Qt-AES-master/qaesencryption.pro
