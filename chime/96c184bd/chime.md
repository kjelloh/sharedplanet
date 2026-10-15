# Todo: Programming - Enable conversion between KeyPath&lt;??&gt; and boost::filesystem::path

```#96c184bd``` *As of 2015-12-04 15:08*

[mail plain/text](mail.txt)

{% raw %}
It seems we would like to get rid of our own RADLib FilePath and replace it with a KeyPath that we may transform to/from boost::filesystem::path?

1) Can we somehow leverage on the boost::filesystem::path functionality to have path-manipulation “done right”?

2) We would like a KeyPath that represents a file-path to be based on the intelligence provide by boost::filesystem::path?

3) Perhaps we could have KeyPath nodes be transformed to a boost::filesystem::path, do the path-manipulation and then transform back to KeyPath?

key_path += “MyFile.txt”

—————————————————

boost::filesystem::path boost_file_path = to_boost_file_path(key_path)

boost_file_path /= “MyFile.txt”

key_path = from_boost_file_path(boost_file_path);

4) This seem like a good starting point to understand boost file-paths (<http://www.boost.org/doc/libs/1_49_0/libs/filesystem/v3/doc/tutorial.html>)?

5) This may be a good example code explaining boost file path composition and decomposition (<http://www.boost.org/doc/libs/1_49_0/libs/filesystem/v3/example/path_info.cpp>)?

6) The key functionality to de-compose a path seem to be path::iterator?

for (path::iterator it(p.begin()), it_end(p.end()); it != it_end; ++it)

cout &lt;&lt; " " &lt;&lt; \*it &lt;&lt; '\\n';

7) Thus, if we make KeyPath nodes strings we may compose a boost file path from a KeyPath and vice versa by just iterating?

a) for (iterator item = key_path.begin(); inter != key_path.end(); iter++ ) boost_path /= \*iter;

b) KeyPath&lt;UTF16String&gt; key_path(path::iterator it(boost_path.begin()), it_end(boost_path.end()))

…

Consider to elaborate on this idea to see how we may have KeyPath be applied as a File Path using boost::filesystem::path as the “engine”?

{% endraw %}
