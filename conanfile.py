from conans import ConanFile

class LCDConanfile(ConanFile):
	name = "lcd"
	version = "0.0.1"
	description = "LCD simulator"
	license = "MIT"
	author = "Arsen Gharagyozyan (arsdever) [arsen.gharagyozyn.96@gmail.com]"
	requires = [
            "spdlog/1.8.0"
        ]
	
	def package(self):
		self.copy("*.h", "include/http", "include")

	def package_info(self):
		self.cpp_info.name = "http"
		self.cpp_info.includedir = ["include"]
