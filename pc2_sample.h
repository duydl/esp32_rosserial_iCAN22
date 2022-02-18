#include <sensor_msgs/PointCloud2.h>
#include <sensor_msgs/PointField.h>
#include <vector>

namespace pc2_sample {

sensor_msgs::PointCloud2 construct_pc_msgs () {

sensor_msgs::PointCloud2 pc;
// pc.header->seq = 0;
// pc.header-?stamp.secs = 0;
// pc.header.stamp.nsecs = 0;
pc.height = 1;
pc.width = 6;

std::vector<sensor_msgs::PointField> field_configuration; 
sensor_msgs::PointField afield;

afield.name = "x";
afield.offset = 0;
afield.datatype = 7;
afield.count = 1;

field_configuration.push_back(afield);

afield.name = "y";
afield.offset = 4;
afield.datatype = 7;
afield.count = 1;

field_configuration.push_back(afield);

afield.name = "z";
afield.offset = 8;
afield.datatype = 7;
afield.count = 1;

field_configuration.push_back(afield);

afield.name = "intensity";
afield.offset = 16;
afield.datatype = 7;
afield.count = 1;

field_configuration.push_back(afield);

// std::vector<sensor_msgs::PointField> vec_values(field_configuration, field_configuration + 4);
pc.fields_length = 4;
pc.st_fields = field_configuration[0];
pc.is_bigendian = false;
pc.point_step = 32;
pc.row_step = 192;
pc.is_dense = true;

std::vector<uint8_t> v = {155, 203, 110, 63, 221, 124, 215, 191, 23, 109, 44, 62, 0, 0, 128, 63, 0, 0, 240, 65, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 122, 248, 112, 63, 67, 161, 217, 191, 218, 88, 116, 62, 0, 0, 128, 63, 0, 0, 16, 66, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 230, 247, 107, 63, 175, 73, 213, 191, 15, 108, 154, 62, 0, 0, 128, 63, 0, 0, 44, 66, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 194, 93, 100, 63, 98, 128, 206, 191, 64, 120, 183, 62, 0, 0, 128, 63, 0, 0, 88, 66, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 251, 235, 115, 63, 18, 240, 221, 191, 216, 62, 49, 62, 0, 0, 128, 63, 0, 0, 0, 66, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 241, 148, 114, 63, 27, 254, 220, 191, 86, 181, 159, 62, 0, 0, 128, 63, 0, 0, 48, 66, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
pc.data_length=192; 
pc.data = &v[0];

return pc;
}
}