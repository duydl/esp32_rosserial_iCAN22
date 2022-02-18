#include <sensor_msgs/PointCloud2.h>
#include <sensor_msgs/PointField.h>

namespace pc2_sample
{

sensor_msgs::PointCloud2 pc;

pc->header.seq = 0;
pc->header.stamp.secs = 0;
pc->header.stamp.nsecs = 0;
pc->height = 1;
pc->width = 9067;

sensor_msgs::PointField field_configuration[4]((new std::vector<sensor_msgs::PointField>); 

field_configuration[0].name = "x";
field_configuration[0].offset = 0;
field_configuration[0].datatype = 7;
field_configuration[0].count = 1;

field_configuration[1].name = "y";
field_configuration[1].offset = 4;
field_configuration[1].datatype = 7;
field_configuration[1].count = 1;

field_configuration[2].name = "z";
field_configuration[2].offset = 8;
field_configuration[2].datatype = 7;
field_configuration[2].count = 1;

field_configuration[3].name = "intensity";
field_configuration[3].offset = 16;
field_configuration[3].datatype = 7;
field_configuration[3].count = 1;

pc->fields = field_configuration;


pc->is_bigendian = false;
pc->point_step = 32;
pc->row_step = 290144;
pc->is_dense = true;
}