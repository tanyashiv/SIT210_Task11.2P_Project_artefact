import sys
from PyQt5.QtWidgets import QApplication, QMainWindow, QPushButton, QVBoxLayout, QWidget, QTextEdit
import serial

"""
ser = serial.Serial('/dev/ttyACMO', 9600)
"""

class MainInterface(QWidget):
    def _init_(self):
        super()._init_()

        self.init_ui()

    def init_ui(self):
        self.setWindowTitle("SIT 210 ")
        self.setFixedSize(700, 800)
        layout = QVBoxLayout()


        button_section1 = QPushButton("LIGHTS")
        button_section2 = QPushButton("DISPENSOR")
        button_section3 = QPushButton("NOTIFICATION")
        
        display_main = QTextEdit()
        s = "ALL THE TEXT HERE PLZ\n"
        display_main.setPlainText(s+ "NOTIFICATION HERE")
        
        display_main.setReadOnly(True)
        
        button_section1.setFixedSize(200, 150)
        button_section2.setFixedSize(200, 150)
        button_section3.setFixedSize(200, 150)
        display_main.setFixedSize(400, 200)
        
        layout.addWidget(button_section1)
        layout.addWidget(button_section2)
        layout.addWidget(button_section3)
        layout.addWidget(display_main)
        
        button_section1.clicked.connect(self.show_section1)
        button_section2.clicked.connect(self.show_section2)
        button_section3.clicked.connect(self.show_section3)

        self.setLayout(layout)
    
    
        
    def show_section1(self):
        self.subsection1 = Subsection1(self)
        self.subsection1.show()
        self.hide()

    def show_section2(self):
        self.subsection2 = Subsection2(self)
        self.subsection2.show()
        self.hide()

    def show_section3(self):
        self.subsection3 = Subsection3(self)
        self.subsection3.show()
        self.hide()
        
    
        
class Subsection(QWidget):
    def _init_(self, main_interface):
        super()._init_()
        self.main_interface = main_interface
        self.init_ui()

    def init_ui(self):
        layout = QVBoxLayout()

        back_button = QPushButton("Back to Main")
        back_button.clicked.connect(self.show_main_interface)

        layout.addWidget(back_button)

        self.setLayout(layout)

    def show_main_interface(self):
        self.main_interface.show()
        self.close()

class Subsection1(Subsection):
    def init_ui(self):
        super().init_ui()

        # Additional buttons and display area for Subsection 1
        button_1 = QPushButton("ROOM 1")
        button_2 = QPushButton("ROOM 2")
        display_1 = QTextEdit()

        layout = self.layout()
        layout.addWidget(button_1)
        layout.addWidget(button_2)
        layout.addWidget(display_1)
        
        button_1.clicked.connect(self.show_room1)
        button_2.clicked.connect(self.show_room2)
        
    def show_room1(self):
        self.subsection4 = Subsection4(self)
        self.subsection4.show()
        self.room1_click()
        self.hide()
    def show_room2(self):
        self.subsection5 = Subsection5(self)
        self.subsection5.show()
        self.room2_click()
        self.hide()
        
    def room1_click(self):
        print("ROOM 1 CLICK")
    
    def room2_click(self):
        print("ROOM 2 CLICK")
        
class Subsection2(Subsection):
    def init_ui(self):
        super().init_ui()

        # Additional buttons and display area for Subsection 2
        button_3 = QPushButton("+1 WATER GLASS")
        button_4 = QPushButton("Button 4")
        display_2 = QTextEdit()

        button_3.clicked.connect(self.AddWater)
        button_4.clicked.connect(self.Option)
        
        layout = self.layout()
        layout.addWidget(button_3)
        layout.addWidget(button_4)
        layout.addWidget(display_2)
    
    def AddWater():
        print("WATER ADDED")
    
    def Option():
        print("SOmeting")

class Subsection3(Subsection):
    def init_ui(self):
        super().init_ui()

        # Additional buttons and display area for Subsection 3
        #button_5 = QPushButton("Button 5")
        #button_6 = QPushButton("Button 6")
        display_3 = QTextEdit()
        s = "This is a text box.\nYou can add text here."
        display_3.setPlainText(s+ "NOTIFICATION HERE")
        
        display_3.setReadOnly(True)
        layout = self.layout() 
        #layout.addWidget(button_5)
        #layout.addWidget(button_6)
        layout.addWidget(display_3)

class Subsection4(Subsection):
    def init_ui(self):
        super().init_ui()

        # Additional buttons and display area for Subsection 3
        button_7 = QPushButton("Light ON krdo")
        button_8 = QPushButton("Light OFF krdo")
        #display_3 = QTextEdit()

        layout = self.layout()
        layout.addWidget(button_7)
        layout.addWidget(button_8)
        
        button_7.clicked.connect(self.Light_On)
        button_8.clicked.connect(self.Light_Off)
    def Light_On(self):
        print("Light ON")
    
    def Light_Off(self):
        print("Light Off")
class Subsection5(Subsection):
    def init_ui(self):
        super().init_ui()

        # Additional buttons and display area for Subsection 3
        button_9 = QPushButton("Light ON krdo")
        button_10 = QPushButton("Light OFF krdo")
        #display_3 = QTextEdit()

        layout = self.layout()
        layout.addWidget(button_9)
        layout.addWidget(button_10)
        
        button_9.clicked.connect(self.Light_On)
        button_10.clicked.connect(self.Light_Off)
        
    def Light_On(self):
        print("Light ON")
    
    def Light_Off(self):
        print("Light Off")

class Subsection6(Subsection):
    def init_ui(self):
        super().init_ui()
        
        
        
        
        
if __name__ == "__main__":
    app = QApplication(sys.argv)
    main_interface = MainInterface()
    main_interface.show()
    sys.exit(app.exec_())