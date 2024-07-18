from pynput import mouse
import logging

# Configure logging
logging.basicConfig(level=logging.INFO, format='%(asctime)s - %(message)s')

class MouseHandler:
    def __init__(self):
        self.listener = mouse.Listener(on_click=self.on_click, on_scroll=self.on_scroll)

    def on_scroll(self, x, y, dx, dy):
        if dy > 0:
            logging.info("Mouse scrolled up")
        else:
            logging.info("Mouse scrolled down")

    def on_click(self, x, y, button, pressed):
        if pressed:
            if button == mouse.Button.left:
                logging.info(f"Left mouse button clicked at ({x}, {y})")
            elif button == mouse.Button.right:
                logging.info(f"Right mouse button clicked at ({x}, {y})")
            elif button == mouse.Button.middle:
                logging.info(f"Middle mouse button clicked at ({x}, {y})")
            elif button == mouse.Button.x1:
                logging.info(f"Forward mouse button clicked at ({x}, {y})")
            elif button == mouse.Button.x2:
                logging.info(f"Backward mouse button clicked at ({x}, {y})")

    def start(self):
        try:
            with self.listener:
                self.listener.join()
        except KeyboardInterrupt:
            logging.info("Mouse listener stopped by user")

def main():
    handler = MouseHandler()
    handler.start()

if __name__ == "__main__":
    main()
