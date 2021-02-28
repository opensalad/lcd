from conans import ConanFile, CMake

class LCDConanfile(ConanFile):
	name = "lcd"
	version = "0.0.1"
	description = "LCD simulator"
	license = "MIT"
	author = "Arsen Gharagyozyan (arsdever) [arsen.gharagyozyn.96@gmail.com]"
	requires = [
		"spdlog/1.8.2",
		"boost/1.75.0@arsdever/stable"
		]
	generators = ["cmake"]
	source_folder = "./"
	build_folder = "./build"

	def build(self):
		cmake = CMake(self)
		cmake.configure()
		cmake.build()
		# cmake.test() # Build the "RUN_TESTS" or "test" target
		# Build the "install" target, defining CMAKE_INSTALL_PREFIX to self.package_folder
		# cmake.install()

	def package(self):
		self.copy("*.h", "include/http", "include")

	def package_info(self):
		self.cpp_info.name = "http"
		self.cpp_info.includedir = ["include"]
