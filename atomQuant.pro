QT -= gui

CONFIG += c++11 console
CONFIG -= app_bundle

# The following define makes your compiler emit warnings if you use
# any Qt feature that has been marked deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target


HEADERS += \
    events.h \
    src/eventhandler.h \
    src/global.h \
    src/log/spdlog/async.h \
    src/log/spdlog/async_logger-inl.h \
    src/log/spdlog/async_logger.h \
    src/log/spdlog/common-inl.h \
    src/log/spdlog/common.h \
    src/log/spdlog/details/backtracer-inl.h \
    src/log/spdlog/details/backtracer.h \
    src/log/spdlog/details/circular_q.h \
    src/log/spdlog/details/console_globals.h \
    src/log/spdlog/details/file_helper-inl.h \
    src/log/spdlog/details/file_helper.h \
    src/log/spdlog/details/fmt_helper.h \
    src/log/spdlog/details/log_msg-inl.h \
    src/log/spdlog/details/log_msg.h \
    src/log/spdlog/details/log_msg_buffer-inl.h \
    src/log/spdlog/details/log_msg_buffer.h \
    src/log/spdlog/details/mpmc_blocking_q.h \
    src/log/spdlog/details/null_mutex.h \
    src/log/spdlog/details/os-inl.h \
    src/log/spdlog/details/os.h \
    src/log/spdlog/details/pattern_formatter-inl.h \
    src/log/spdlog/details/pattern_formatter.h \
    src/log/spdlog/details/periodic_worker-inl.h \
    src/log/spdlog/details/periodic_worker.h \
    src/log/spdlog/details/registry-inl.h \
    src/log/spdlog/details/registry.h \
    src/log/spdlog/details/synchronous_factory.h \
    src/log/spdlog/details/thread_pool-inl.h \
    src/log/spdlog/details/thread_pool.h \
    src/log/spdlog/fmt/bin_to_hex.h \
    src/log/spdlog/fmt/bundled/chrono.h \
    src/log/spdlog/fmt/bundled/color.h \
    src/log/spdlog/fmt/bundled/compile.h \
    src/log/spdlog/fmt/bundled/core.h \
    src/log/spdlog/fmt/bundled/format-inl.h \
    src/log/spdlog/fmt/bundled/format.h \
    src/log/spdlog/fmt/bundled/locale.h \
    src/log/spdlog/fmt/bundled/ostream.h \
    src/log/spdlog/fmt/bundled/posix.h \
    src/log/spdlog/fmt/bundled/printf.h \
    src/log/spdlog/fmt/bundled/ranges.h \
    src/log/spdlog/fmt/bundled/safe-duration-cast.h \
    src/log/spdlog/fmt/fmt.h \
    src/log/spdlog/fmt/ostr.h \
    src/log/spdlog/formatter.h \
    src/log/spdlog/logger-inl.h \
    src/log/spdlog/logger.h \
    src/log/spdlog/sinks/android_sink.h \
    src/log/spdlog/sinks/ansicolor_sink-inl.h \
    src/log/spdlog/sinks/ansicolor_sink.h \
    src/log/spdlog/sinks/base_sink-inl.h \
    src/log/spdlog/sinks/base_sink.h \
    src/log/spdlog/sinks/basic_file_sink-inl.h \
    src/log/spdlog/sinks/basic_file_sink.h \
    src/log/spdlog/sinks/daily_file_sink.h \
    src/log/spdlog/sinks/dist_sink.h \
    src/log/spdlog/sinks/dup_filter_sink.h \
    src/log/spdlog/sinks/msvc_sink.h \
    src/log/spdlog/sinks/null_sink.h \
    src/log/spdlog/sinks/ostream_sink.h \
    src/log/spdlog/sinks/rotating_file_sink-inl.h \
    src/log/spdlog/sinks/rotating_file_sink.h \
    src/log/spdlog/sinks/sink-inl.h \
    src/log/spdlog/sinks/sink.h \
    src/log/spdlog/sinks/stdout_color_sinks-inl.h \
    src/log/spdlog/sinks/stdout_color_sinks.h \
    src/log/spdlog/sinks/stdout_sinks-inl.h \
    src/log/spdlog/sinks/stdout_sinks.h \
    src/log/spdlog/sinks/syslog_sink.h \
    src/log/spdlog/sinks/systemd_sink.h \
    src/log/spdlog/sinks/wincolor_sink-inl.h \
    src/log/spdlog/sinks/wincolor_sink.h \
    src/log/spdlog/spdlog-inl.h \
    src/log/spdlog/spdlog.h \
    src/log/spdlog/tweakme.h \
    src/log/spdlog/version.h \
    src/quotation/ctp/ctpquotation.h \
    src/quotation/ctp/ctpquotation.h \
    src/quotation/quotation.h \
    src/strategy/strategy.h \
    src/strategy/strategymanager.h \
    userStrategy/twinmovingaverage.h


SOURCES += \
        src/eventhandler.cpp \
        src/global.cpp \
        src/main.cpp \
        src/quotation/ctp/ctpquotation.cpp \
        src/quotation/ctp/ctpquotation.cpp \
        src/quotation/quotation.cpp \
        src/strategy/strategy.cpp \
        src/strategy/strategymanager.cpp \
        userStrategy/twinmovingaverage.cpp


DISTFILES += \
    README.md \
    setting.ini \
    src/log/spdlog/fmt/bundled/LICENSE.rst


win32 {
    !contains(QMAKE_TARGET.arch, x86_64) {
        message("x86 build")
    } else {
        message("x86_64 build")
        #ctp lib
        CTP_DIR = $$PWD/thirdparty/ctp/6.3.15/windows64
        INCLUDEPATH += $$CTP_DIR
        LIBS += -L$$CTP_DIR -lthostmduserapi_se -lthosttraderapi_se
        QMAKE_POST_LINK += copy /Y $$shell_path($$CTP_DIR/thostmduserapi_se.dll) $$shell_path($$DESTDIR) & copy /Y $$shell_path($$CTP_DIR/thosttraderapi_se.dll) $$shell_path($$DESTDIR)

    }
}


linux {
    !contains(QMAKE_TARGET.arch, x86_64) {
        message("linux x86 build")
        #ctp lib
        CTP_DIR = $$PWD/thirdparty/ctp/6.3.15/linux64
        INCLUDEPATH += $$CTP_DIR
        LIBS += -L$$CTP_DIR -lthostmduserapi_se -lthosttraderapi_se
        QMAKE_POST_LINK += copy /Y $$shell_path($$CTP_DIR/thostmduserapi_se.so) $$shell_path($$DESTDIR) & copy /Y $$shell_path($$CTP_DIR/thosttraderapi_se.so) $$shell_path($$DESTDIR)
    } else {
        message("linux x86_64 build")
        #ctp lib
        CTP_DIR = $$PWD/thirdparty/ctp/6.3.15/linux64
        INCLUDEPATH += $$CTP_DIR
        LIBS += -L$$CTP_DIR -lthostmduserapi_se -lthosttraderapi_se
        QMAKE_POST_LINK += copy /Y $$shell_path($$CTP_DIR/thostmduserapi_se.so) $$shell_path($$DESTDIR) & copy /Y $$shell_path($$CTP_DIR/thosttraderapi_se.so) $$shell_path($$DESTDIR)

    }
}

#src
SRC_DIR = $$PWD/src
INCLUDEPATH += $$SRC_DIR

#spdlog
SPDLOG_DIR = $$PWD/src/log
INCLUDEPATH += $$SPDLOG_DIR

#quotation
QUOTATION_DIR = $$PWD/src/quotation
INCLUDEPATH += \
        $$QUOTATION_DIR \
        $$QUOTATION_DIR/ctp

#strategy
STRATEGY_DIR = $$PWD/src/strategy
INCLUDEPATH += \
        $$STRATEGY_DIR \
