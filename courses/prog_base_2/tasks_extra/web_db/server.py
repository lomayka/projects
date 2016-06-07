# -*- coding: utf-8 -*-
import cgi
import json
import urlparse
from BaseHTTPServer import BaseHTTPRequestHandler, HTTPServer

import simplejson as simplejson

from data_base import DB_Handler


class HttpProcessor(BaseHTTPRequestHandler):
    bootpath = '<link href="https://maxcdn.bootstrapcdn.com/bootstrap/3.3.6/css/bootstrap.min.css" ' \
               'rel="stylesheet" ' \
               'integrity="sha384-1q8mTJOASx8j1Au+a5WDVnPi2lkFfwwEAa8hDDdjZlpLegxhjVME1fgjWPGmkzs7" c' \
               'rossorigin="anonymous">'
    warning = '<html><head>{0}</head><boody><h1 class="bg-danger text-center">' \
              'Wrong input data try again</h1></body>'.format(bootpath)
    success = '<html><head>{0}</head><boody><h1 class=\"bg-success text-center\">Successfully inserted' \
              '</h1></body>'.format(bootpath)
    success_update = '<html><head>{0}</head><boody><h1 class=\"bg-success text-center\">Successfully updated' \
              '</h1></body>'.format(bootpath)

    def do_GET(self):
        test = DB_Handler('test');
        test.connect()
        if self.path == "/test":
            self.send_response(200)
            self.send_header('content-type', 'text/html')
            self.end_headers()

            self.wfile.write('<html>'
                             '<head>'
                             + self.bootpath +
                             '</head>'
                             '<body>'
                             '<table class = "table table-striped table-bordered">'
                             '<thead>'
                             '<tr class = "success">'
                             '<th>Name</th>'
                             '<th>Surname</th>'
                             '<th>mail</th>'
                             '</tr>'
                             '</thead>'
                             '<tbody>'
                             '<tr>'
                             '<td>%s</td>'
                             '<td>Ivanov</td>'
                             '<td>ivan@example.com</td>'
                             '</tr>'
                             '<tr>'
                             '<td>Ivan</td>'
                             '<td>Ivanov</td>'
                             '<td>ivan@example.com</td>'
                             '</tr>'
                             '</tbody>'
                             '</table>'
                             '<button type="button" class="btn btn-success">Confirm</button>'
                             '</body>'
                             '</html>' % 'Vasya')

        elif "/test/" in self.path:
            self.send_response(200)
            self.send_header('content-type', 'text/html')
            self.end_headers()
            if self.path[len("/test/"):].isdigit():
                self.wfile.write(int(self.path[len("/test/"):]))
            else:
                self.wfile.write("You enter dich")
        elif self.path == "/db":
            self.send_response(200)
            self.send_header('content-type', 'text/html')
            self.end_headers()
            messege = '<html>' \
                      '<head>'\
                      + self.bootpath \
                      +'</head>' \
                       '<body>' \
                       '<table class = "table table-striped table-bordered">'\
                       '<thead>' \
                       '<tr class = "success">' \
                       '<th>Name</th>' \
                       '</tr>' \
                       '</thead>'
            for row in test.getTablesName():
                messege = messege + '<tbody><tr><td><a href="/table/%s">%s</a></td>' %(row,row)
            messege = messege + '</body></html>'
            self.wfile.write(messege)
        elif "/table/" in self.path:
            self.send_response(200)
            self.send_header('content-type', 'text/html')
            self.end_headers()
            self.path = self.path[len("/test/")+1:]
            status = 0
            for row in test.getTablesName():
                if self.path == row:
                    messege = '<html>' \
                              '<head>'\
                             + self.bootpath \
                             +'</head>' \
                              '<body>' \
                              '<div style = "margin-top:15px" > </div >' \
                              '<table class = "table table-striped table-bordered">'\
                              '<thead>' \
                              '<tr class = "success">'
                    count = 0
                    id_num = 0
                    for r in test.getTableColums(row):
                        messege += '<th>%s</th>' % (r)
                        if r == 'id':
                            id_num = count
                            print id_num
                        count += 1
                    messege += '<th>Action</th></tr></thead><tbody>'
                    l = 0
                    for r in test.getTableContent(row):
                        messege += '<tr>'
                        j = 0
                        while j < count:
                            messege += '<td>%s</td>' % (str(r[j]))
                            j += 1
                        request = 'DELETE FROM %s WHERE id = %s'  % (row,str(r[id_num]))
                        messege += '<td><a href="/%s/%s""><button type = "submit" ' \
                                   'class ="btn btn-warning col-sm-offset-2" >Change</button></a></td></tr>' % (row,str(r[id_num]))
                        l += 1
                    messege += '</tbody><form action="/db" method="POST" role="form">' \
                               '<div class = "form-group">' \
                               '<div class = "row">'
                    k = 0
                    tp = ''
                    for r in test.getTableColums(row):
                        if test.getTableColumsType(row)[k] == 'integer': tp = 'number'
                        elif (test.getTableColumsType(row)[k] == 'text') | (test.getTableColumsType(row)[k] == 'character varying'): tp = 'text'
                        messege +=  '<div class = "col-md-2"><label for="%s" class = "col-sm-offset-2">%s</label><input type="%s"' \
                                    ' class="form-control col-sm-offset-2"  name="%s" placeholder="Enter %s here"></div>' % (r,r,tp,r,r)
                        k += 1
                    if len(test.getTableColumsType(row)) != 0:
                      messege +=  '</div></div><button type = "submit" class ="btn btn-success col-sm-offset-2" >' \
                                  ' Insert </button><div style = "margin:15px"></div>' \
                                  '<div class = "row col-md-2 col-md-push-4"><label for="table" class = "col-sm-offset-2">Table</label>' \
                                  '<input type="text" readonly class="form-control col-sm-offset-2"  ' \
                                  'name="table" value="%s"><div style = "margin:15px"></div></div>' \
                                  '</div></form>'\
                                  '</body></html>' % (row)


                    self.wfile.write(messege)

                    status = 1

            if status == 0:
                self.wfile.write("404 page not found")
        else:
            k = 0
            for row in test.getTablesName():
                if '/' + row +'/' in self.path:
                    if self.path[len(row)+2:].isdigit():
                        k = 0
                        response = '<html><head>' + self.bootpath + '<head><body>' \
                                                                '<form action="/update" method="POST" role="form">' \
                                                                '<div class = "form-group">' \
                                                                '<div class = "row">'
                        for r in test.getTableColums(row):
                            if test.getTableColumsType(row)[k] == 'integer': tp = 'number'
                            elif (test.getTableColumsType(row)[k] == 'text') | (test.getTableColumsType(row)[k] == 'character varying'): tp = 'text'
                            response += '<div class = "col-md-2"><label for="%s" class = "col-sm-offset-2">%s</label><input type="%s"' \
                                   ' class="form-control col-sm-offset-2"  name="%s" placeholder="Enter %s here"></div>' % (r, r, tp, r, r)
                            k += 1
                            print r
                        if len(test.getTableColumsType(row)) != 0:
                            response += '</div></div><button type = "submit" class ="btn btn-success col-sm-offset-2" >' \
                                        ' Insert </button><div style = "margin:15px"></div>' \
                                        '<div class = "row col-md-2 col-md-push-4"><label for="table" class = "col-sm-offset-2">Table</label>' \
                                        '<input type="text" readonly class="form-control col-sm-offset-2"  ' \
                                        'name="table" value="%s">' \
                                        '<label for="id" class = "col-sm-offset-2">Id</label>' \
                                        '<input type="text" readonly class="form-control col-sm-offset-2"' \
                                        'name="num" value="%s"><div style = "margin:15px"></div>' \
                                        '</form>' \
                                        '<a href="http://127.0.0.1/table/%s" onclick="doDelete()">' \
                                        '<h3 class="text-danger">Delete</h3></a>' \
                                        '<script>function doDelete(){' \
                                        'var xhttp = new XMLHttpRequest();' \
                                        'xhttp.open("DELETE", "http://127.0.0.1/%s/%s", true);' \
                                        'xhttp.send();' \
                                        '}' \
                                        '</script>' \
                                        '</body>' % (row,self.path[len(row)+2:],row,row,self.path[len(row)+2:])
                        self.wfile.write(response)
                    else:
                        self.wfile.write("You enter dich")
    def do_POST(self):
        test = DB_Handler('test')
        test.connect()
        self.send_response(200)
        self.send_header('content-type', 'text/html')
        self.end_headers()
        content_len = int(self.headers.getheader('content-length', 0))
        post_body = self.rfile.read(content_len)
        part =  post_body.split('&')
        i = 0
        tlist = []
        while i < len(part):
            s = part[i]
            tlist.append(s[s.index('=')+1:])
            i += 1
        print post_body
        if self.path =='/db':
            status = 1
            j = 0
            while j < len(tlist)-1:
                if len(tlist[j]) == 0: status = 0
                j += 1
            if status != 0:
              messege = 'INSERT into %s VALUES(' % tlist[len(tlist)-1]
              i = 0
              while i < len(tlist)-1:
               if test.getTableColumsType(tlist[len(tlist)-1])[i] == 'integer' : messege += tlist[i]
               elif (test.getTableColumsType(tlist[len(tlist)-1])[i] == 'character varying') | \
                    (test.getTableColumsType(tlist[len(tlist)-1])[i] == 'text') : messege += "'" + tlist[i] + "'"
               if i < len(tlist)-2:
                   messege += ','
               i += 1
              messege += ');'
              print messege
              print  test.getTableColumsType(tlist[len(tlist) - 1])[0]
              if test.insert(messege) == 1:
                  self.wfile.write(self.success)
              else:
                  self.wfile.write(self.warning)

            else:
                self.wfile.write(self.warning)
        elif self.path == '/update':
            i = 0
            status = 1
            while i < len(tlist)- 2:
                if len(tlist[i]) == 0: status = 0
                i += 1
            if status != 0:
                messege = 'UPDATE %s SET ' % tlist[len(tlist)-2]
                i = 0
                while i < len(tlist)-2:
                    messege += test.getTableColums(tlist[len(tlist)-2])[i] + '='
                    if test.getTableColumsType(tlist[len(tlist) - 2])[i] == 'integer':
                        messege += tlist[i]
                    elif (test.getTableColumsType(tlist[len(tlist) - 2])[i] == 'character varying') | \
                            (test.getTableColumsType(tlist[len(tlist) - 2])[i] == 'text'):
                        messege += "'" + tlist[i] + "'"
                    if i < len(tlist) - 3:
                        messege += ','
                    i += 1
                messege += ' WHERE id = %s' % tlist[len(tlist)-1]
                print messege
                if test.insert(messege) == 1:
                    self.wfile.write(self.success_update)
                else:
                    self.wfile.write(self.warning)
            else:
                self.wfile.write(self.warning)
    def do_DELETE(self):
        test = DB_Handler('test')
        test.connect()
        self.send_response(200)
        self.send_header('content-type', 'text/html')
        self.end_headers()
        for row in test.getTablesName():
            if '/' + row + '/' in self.path:
                if self.path[len(row) + 2:].isdigit():
                    request = 'DELETE FROM %s WHERE id = %s' % (row,self.path[len(row) + 2:])
                    test.insert(request)








serv = HTTPServer(("localhost", 80), HttpProcessor)
serv.serve_forever()

