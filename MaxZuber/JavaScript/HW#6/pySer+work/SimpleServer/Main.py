'''
@author: suschuk
'''

from http.server import BaseHTTPRequestHandler
import urllib.parse 
import cgi

class GetPostHandler(BaseHTTPRequestHandler):
    
    def do_POST(self):
        # Parse the form data posted
        form = cgi.FieldStorage(
            fp=self.rfile, 
            headers=self.headers,
            environ={'REQUEST_METHOD':'POST',
                     'CONTENT_TYPE':self.headers['Content-Type'],
                     })

        # Begin the response
        self.send_response(200)
        self.end_headers()
        
        message = "<html><body>"
        self.wfile.write(bytes(message, "utf-8"))
        message = '<p id="client"><span>Client:</span><span>%s</span></p>\n' % str(self.client_address)
        print(message)
        self.wfile.write(bytes(message, "utf-8"))
        message = '<p id="user-agent"><span>User-agent:</span><span>%s</span></p>\n' % str(self.headers['user-agent'])
        print(message)
        self.wfile.write(bytes(message, "utf-8"))
        message = '<p id="path"><span>Path:</span><span>%s</span></p>\n' % self.path
        print(message)
        self.wfile.write(bytes(message, "utf-8"))
        message = '<p id="form-data"><span>Form data:</span>\n'
        self.wfile.write(bytes(message, "utf-8"))

        # Echo back information about what was posted in the form
        for field in form.keys():
            field_item = form[field]
            if field_item.filename:
                # The field contains an uploaded file
                file_data = field_item.file.read()
                file_len = len(file_data)
                del file_data
                message = '<span>\tUploaded %s as "%s" (%d bytes)</span></p>\n' % (field, field_item.filename, file_len)
                self.wfile.write(bytes(message, "utf-8"))
            else:
                # Regular form value
                message = '<p id="form-value">\t<span>%s</span>:<span>%s</span></p>\n' % (field, form[field].value)
                self.wfile.write(bytes(message, "utf-8"))
                
        message = '<p id="requested-contents">This is requested contents</p>'
        self.wfile.write(bytes(message, "utf-8"))
        # pathis a path in . (current dir)
        if( self.path != '/'):
            message = open("." + self.path).read()
            self.wfile.write(bytes(message, "utf-8"))
        message = "</body></html>"
        self.wfile.write(bytes(message, "utf-8"))
        return
    
    def do_GET(self):
        parsed_path = urllib.parse.urlparse(self.path)
        message_parts = [
                'CLIENT VALUES:',
                'client_address=%s (%s)' % (self.client_address,
                                            self.address_string()),
                'command=%s' % self.command,
                'path=%s' % self.path,
                'real path=%s' % parsed_path.path,
                'query=%s' % parsed_path.query,
                'request_version=%s' % self.request_version,
                '',
                'SERVER VALUES:',
                'server_version=%s' % self.server_version,
                'sys_version=%s' % self.sys_version,
                'protocol_version=%s' % self.protocol_version,
                '',
                'HEADERS RECEIVED:',
                ]
        for name, value in sorted(self.headers.items()):
            message_parts.append('%s=%s' % (name, value.rstrip()))
        message_parts.append('')
        message = '\r\n'.join(message_parts)
        self.send_response(200)
        self.end_headers()
        self.wfile.write(bytes(message, "utf-8"))
        if( self.path != '/'):
            message = open("." + self.path).read()
            self.wfile.write(bytes(message, "utf-8"))
#       self.wfile.write(bytes("</body></html>", "utf-8"))
        
        return

if __name__ == '__main__':
    from http.server import HTTPServer
    server = HTTPServer(('', 80), GetPostHandler)
    print('Starting server, use <Ctrl-C> to stop')
    server.serve_forever()