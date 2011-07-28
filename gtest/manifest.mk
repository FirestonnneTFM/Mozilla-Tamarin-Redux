STATIC_LIBRARIES += gtest
gtest_BUILD_ALL = 1

gtest_CXXSRCS := $(gtest_CXXSRCS) \
  $(curdir)/gtest_main.cpp \
  $(curdir)/gtest-all.cpp \
  $(NULL)
