# Polaris-PHP SDK method uses a document

## PolarisClient

### new PolarisClient(array())

> Method use

`PolarisClient` More to create a` PolarisClient` instance for use

> Parameter Description

*Function*

| Parameter Name | Parameter Type | Parameter                                                     |
| :------------- | :------------- | :------------------------------------------------------------ |
| `config_path`  | String         | Settings the file path information for the configuration file |
| `log_dir`      | String         | Set the location where SDK itself is saved                    |

> Specific code use example

```php
$param = array(
    "config_path" => "./polaris.yaml",
    "log_dir" => "./"
);

$polaris_client = new PolarisClient($param)
```

### InitProvider

> Method use

Related Abilities for Open `PolarisClient`

- Registration service instance
- Anti-registration example
- Report service instance heartbeat

> Parameter Description

This method is incapable of parameters

> Specific use example

```php
$param = array(
    "config_path" => "./polaris.yaml",
    "log_dir" => "./"
);

$polaris_client = new PolarisClient($param)

$polaris_client->InitProvider();
```

### InitConsumer

> Method use

Related Ability to Open `PolarisClient`

- Get an instance of a single service
- Get instances of single services
- Report Service Call Information
- ...

> Parameter Description

This method is incapable of parameters

> Specific code use example

```php
$param = array(
    "config_path" => "./polaris.yaml",
    "log_dir" => "./"
);

$polaris_client = new PolarisClient($param);

$polaris_client->InitConsumer();
```

### InitLimit

> Method use

Related Abilities for Open `PolarisClient`

- Get quota information for the current limiting rules
- View the current limit result
- Update request quota call results
- ...

> Parameter Description

This method is incapable of parameters

> Specific code use example

```php
$param = array(
    "config_path" => "./polaris.yaml",
    "log_dir" => "./"
);

$polaris_client = new PolarisClient($param);

$polaris_client->InitLimit();
```

---

## ProviderAPI

### Register

> Method use

Register a service instance to the Arctic star

> Parameter Description

*Function into the parade*

| First-class parameter name | Secondary parameter name | Parameter Type            | Parameter                                                             |
| :----------- | :----------- | :------------------ | :------------------------------------------------------------------- |
| `timeout`    |              | long                | Timeout, unit millisecond|
| `flowId`     |              | long                | Id identification ID of this request|
| `instance`   |              | map<string, object> |                                                                      |
|              | `namespace`  | string              | Namespace where service is located|
|              | `service`    | string              | service name|
|              | `host`       | string              | Instance IP|
|              | `port`       | string              | The port of the instance, the string number: "100"|
|              | `protocol`   | string              | Example port protocol|
|              | `priority`   | string              | Example priority, string number: "100"|
|              | `weight`     | string              | The weight of the instance, string number: "100"|
|              | `version`    | string              | Example version|
|              | `vpc_id`     | string              | VPC_ID information in the instance|
|              | `heartbeat`  | string              | Whether to open the heart server to perform a health check to this instance, EG: "TRUE"|
|              | `ttl`        | string              | Heart hopping time, unit is second, only in `Heartbeat` to take effect under` True`, EG: "100"|
|              | `metadata`   | map<string, string> | Instance label information|

*Function execution returns*

| Parameter Name | Parameter Type | Parameter                                             | Example |
| :------------- | :------------- | :---------------------------------------------------- | :------ |
| `code`         | int            | method Perform status code                            |
| `err_msg`      | String         | Error message                                         |         |
| `instance_id`  | String         | Successful registration, unique ID ID of the instance |         |

> Specific code use example

```php
$polaris_client = new PolarisClient(array());

// 初始化服务提供者的能力
$polaris_client->InitProvider();

$instance_info = array(
    "namespace" => "default",
    "service" => "php_ext_test",
    "host" => "127.0.0.3",
    "port" => "8080",
    "metadata" => array(
        "env" => "pre"
    ),
    "vpc_id" => "test_vpc",
);

$timeout = 500;
$flow_id = 123456;

$res = $polaris_client->Register($instance_info, $timeout, $flow_id);
var_dump($res);
```

### Deregister

> Method use

Provide an instance anti-registration function, that is, active to completely delete the instance from the Arctic stars

> Parameter Description

*Function into the parade*

| First Level Parameter Name | Secondary Parameter Name | Parameter Type       | Parameter                              |
| :------------------------- | :----------------------- | :------------------- | :------------------------------------- |
| `timeout`                  |                          | Long                 | Timeout, unit milliseconds             |
| `flowid`                   |                          | Long                 | Identification ID of this request      |
| `instance`                 |                          | Map <string, object> |                                        |
|                            | `namespace`              | String               | Namespace where the service is located |
|                            | `service`                | String               | Service Name                           |
|                            | `host`                   | String               | IP                                     |
|                            | `port`                   | String               | Example Port, String Number:" 100 "    |
|                            | `vpc_id`                 | String               | VPC_ID Information in Example          |

*Function execution Back*

| Parameter Name | Parameter Type | Parameter                  |
| :------------- | :------------- | :------------------------- |
| `code`         | int            | method Perform status code |
| `err_msg`      | String         | Error message              |

> Specific code use example

```php
$polaris_client = new PolarisClient(array());

// 初始化服务提供者的能力
$polaris_client->InitProvider();

$instance_info = array(
    "namespace" => "default",
    "service" => "php_ext_test",
    "host" => "127.0.0.3",
    "port" => "8080",
    "vpc_id" => "test_vpc",
);

$timeout = 500;
$flow_id = 123456;

$res = $polaris_client->Deregister($instance_info, $timeout, $flow_id);
var_dump($res);
```

### Heartbeat

> Method use

Provide a newspaper heartbeat function

> Parameter Description

*Function into the parade*

| Parameter Name | Parameter Type | Parameter                              |
| :------------- | :------------- | :------------------------------------- |
| `namespace`    | String         | Namespace where the service is located |
| `service`      | String         | Service Name                           |
| `host`         | String         | IP                                     |
| `port`         | String         | Port, String Number:" 100 "            |
| `vpc_id`       | String         | VPC_ID Information in Example          |

* Function execution Back *

| Parameter Name | Parameter Type | Parameter                  |
| :------------- | :------------- | :------------------------- |
| `code`         | int            | method Perform status code |
| `err_msg`      | String         | Error message              |

> Specific code use example

```php
$polaris_client = new PolarisClient(array());

// 初始化服务提供者的能力
$polaris_client->InitProvider();

$heartbeat_info = array(
    "namespace" => "default",
    "service" => "php_ext_test",
    "host" => "127.0.0.3",
    "port" => "8080",
    "vpc_id" => "test_vpc",
);


$res = $polaris_client->Heartbeat($heartbeat_info);
var_dump($res);
```

---

## ConsmerAPI

### premise

| KEY                      | Value Category | Role                                                    |
| :----------------------- | :------------- | :------------------------------------------------------ |
| `load_balance_type`      | Weightedrandom | Weight Random                                           |
|                          | RingHash       | Consistency Hash Load Balancing                         |
|                          | MAGLEV         | Consistency Hash: Maglev Algorithm                      |
|                          | L5CST          | Compatible with L5 Hash                                 |
|                          |                | Simplehash                                              | Hash_Key% Total Example Number Select Service Instance |
|                          | CMURMURHASH    | Compliance has been compatible with BrPC C_Murmur       |
|                          | LocalityAware  | Load balancing of BRPC Locality_aware                   |
|                          | DEFAULT        | Load balancing algorithms using global configuration    |
|                          |                |                                                         |                                                        |  |
| `metadata_failover_type` | NOTKEY         | Returns Nodes that do not include metadata routing keys |
|                          |                | All                                                     | Downstrades Returns all nodes                          |
|                          | NONE           | Default is not downgraded                               |
|                          |                |                                                         |                                                        |  |
| `weight_type`            | static         | Static Weight                                           |
|                          | Dynamic        | Dynamic weights                                         |
|                          |                |                                                         |                                                        |  |
| `ret_status`             | Error          | Service instance error                                  |
|                          | TIMEOUT        | Serving Examples                                        |
|                          | OK             | Service instance normal                                 |

### InitService

> Method use

Used to initialize service data in advance

> Parameter Description

*Request parameters*


| First-class parameter name | Secondary parameter name             | Three-level parameter name | Parameter Type            | Parameter                                                       |
| :----------- | :----------------------- | :----------- | :------------------ | :------------------------------------------------------------- |
| `timeout`    |                          |              | long                | Timeout, unit millisecond |
| `flowId`     |                          |              | long                | Id identification ID of this request |
| `instance`   |                          |              | map<string, object> |                                                                |
|              | `namespace`              |              | string              | Namespace where the service is located |
|              | `service`                |              | string              | Templated service name |
|              | `version`                |              | string              | Example version |
|              | `vpc_id`                 |              | string              | VPC_ID information in the instance |
|              | `metadata`               |              | map<string, string> | Set the metadata for metadata routes |
|              | `canary`                 |              | string              | Set which Melots service instance |
|              | `source_set_name`        |              | string              | Set the service under the set of calls |
|              | `ignore_half_open`       |              | string              | Set whether to skip the semi-open detection node, EG: "True" |
|              | `hash_string`            |              | string              | Set a Hash string for consistency hash load balancing algorithm |
|              | `hash_key`               |              | string              | Sethash Key for consistency hash load balancing algorithms, EG: "123" |
|              | `replicate_index`        |              | string              | Get a copy instance when used for consistency hash algorithms, EG: "123" |
|              | `backup_instance_num`    |              | string              | Set the number of instances used to retry.Optional, the default does not return instances used for retry, EG: "123" |
|              | `load_balance_type`      |              | string              | Set the load balancing type.Optional, default use of the type set in the configuration file |
|              | `metadata_failover_type` |              | string              | Set the downgrade policy when the metadata routing failed, the default is not degraded |
|              | `labels`                 |              | map<string, string> | Set the request label for interface level fuse |
|              | `source`                 |              | map<string, object> | Set source service information for service routing calculations.Optional |
|              |                          | `namespace`  | string              | Instance label information |
|              |                          | `service`    | string              | Instance label information |
|              |                          | `metadata`   | map<string, string> | Instance label information |

*Function execution returns*

| parameter name  | Parameter Type | Parameter       | Example |
| :-------- | :------- | :------------- | :--- |
| `code`    | int      | Method execution status code |      |
| `err_msg` | string   | Error message |      |

> Specific code use example

```php
$polaris_client = new PolarisClient(array());

// 初始化服务提供者的能力
$polaris_client->InitConsumer();

$init_service_info = array(
    "namespace" => "default",
    "service" => "php_ext_test",
    "vpc_id" => "test_vpc",
    "labels" => array(
        "user_id" => "uin_001"
    ),
    "source_service" => array(
        "namespace" => "",
        "service" => "",
        "metadata" => array(
            "env" => "pre"
        )
    )
);

$timeout = 500;
$flow_id = 123456;

$res = $polaris_client->InitService($init_service_info, $timeout, $flow_id);
var_dump($res);
```

### GetOneInstance

> Method use

Used to initialize service data in advance

> Parameter Description

*Request parameters*

| First-class parameter name | Secondary parameter name             | Three-level parameter name | Parameter Type            | Parameter                                                |
| :----------- | :----------------------- | :----------- | :------------------ | :------------------------------------------------------ |
| `timeout`    |                          |              | long                | Timeout, unit millisecond |
| `flowId`     |                          |              | long                | Id identification ID of this request |
| `instance`   |                          |              | map<string, object> |                                                         |
|              | `namespace`              |              | string              | Namespace where the service is located |
|              | `service`                |              | string              | Templated service name |
|              | `version`                |              | string              | Example version |
|              | `vpc_id`                 |              | string              | VPC_ID information in the instance |
|              | `metadata`               |              | map<string, string> | Set the metadata for metadata routes |
|              | `canary`                 |              | string              | Set which Melots service instance |
|              | `source_set_name`        |              | string              | Set the service under the set of calls |
|              | `ignore_half_open`       |              | string              | Set whether to skip the semi-open detection node, EG: "True" or "false" |
|              | `hash_string`            |              | string              | Set the Hash string for consistency hash load balancing algorithm, EG: "100" |
|              | `hash_key`               |              | string              | Set Hash Key for consistency hash load balancing algorithm, EG: "100" |
|              | `replicate_index`        |              | string              | Get a copy instance when used for consistency hash algorithm, EG: "100" |
|              | `backup_instance_num`    |              | string              | Set the number of instances used to retry.Optional, default does not return an example for retry |
|              | `load_balance_type`      |              | string              | Set the load balancing type.Optional, default use of the type set in the configuration file |
|              | `metadata_failover_type` |              | string              | Set the downgrade policy when the metadata routing failed, the default is not degraded |
|              | `labels`                 |              | map<string, string> | Set the request label for interface level fuse |
|              | `source`                 |              | map<string, object> | Set source service information for service routing calculations.Optional |
|              |                          | `namespace`  | string              | Instance label information |
|              |                          | `service`    | string              | Instance label information |
|              |                          | `metadata`   | map<string, string> | Instance label information |

*Function execution returns*

| First-class parameter name | Secondary parameter name  | Three-level parameter name          | Parameter Type            | Parameter                 |
| :----------- | :------------ | :-------------------- | :------------------ | :----------------------- |
| `code`       |               |                       | int                 | Method execution status code|
| `err_msg`    |               |                       | string              | Error message|
| `response`   |               |                       | map<string, object> | InstancesResponse|
|              | `flow_id`     |                       | long                | Request water|
|              | `service`     |                       | string              | Service Name|
|              | `namespace`   |                       | string              | Namespaces|
|              | `revision`    |                       | string              | Version Information|
|              | `metadata`    |                       | map<string, string> | Service metadata|
|              | `weight_type` |                       | string              | Weight type|
|              | `subset`      |                       | map<string, string> | Subset|
|              | `instances`   |                       | map<string, object> | Service instance list|
|              |               | `instance_id`         | string              | Service instance ID|
|              |               | `host`                | string              | Service node IP or domain name|
|              |               | `port`                | int                 | Node port number|
|              |               | `container_name`      | string              | Container name in instance metadata information|
|              |               | `internal_set_name`   | string              | SET name in instance metadata information|
|              |               | `logic_set`           | string              | Instance logicset information|
|              |               | `region`              | string              | location region|
|              |               | `zone`                | string              | location zone|
|              |               | `campus`              | string              | location campus|
|              |               | `vpc_id`              | string              | Get service instance VPC ID|
|              |               | `protocol`            | string              | Instance protocol information|
|              |               | `version`             | int                 | Instance version number information|
|              |               | `weight`              | int                 | Example static weight value, 0-1000|
|              |               | `priority`            | int                 | Instance priority|
|              |               | `dynamic_weight`      | int                 | Instance dynamic weight|
|              |               | `hash_key`            | int                 | GetHash|
|              |               | `locality_aware_info` | int                 | locality_aware_info|
|              |               | `healthy`             | bool                | Instance health status|
|              |               | `isola`               | bool                | Instance isolation state|
|              |               | `metadata`            | map<string, string> | Example metadata information|

> Specific code use example

```php
$polaris_client = new PolarisClient(array());

// 初始化服务提供者的能力
$polaris_client->InitConsumer();

$init_service_info = array(
    "namespace" => "default",
    "service" => "php_ext_test",
    "vpc_id" => "test_vpc",
    "source_service" => array(
        "namespace" => "",
        "service" => "",
        "metadata" => array(
            "env" => "pre"
        )
    )
);

$timeout = 500;
$flow_id = 123456;

$res = $polaris_client->GetOneInstance($init_service_info, $timeout, $flow_id);
var_dump($res);
```

### GetInstances

> 方法用途

用于提前初始化服务数据

> 参数描述

*请求参数*

| 参数名称   |                                     |             | 参数类型            | 参数用途                                                                     |
| :--------- | :---------------------------------- | :---------- | :------------------ | :--------------------------------------------------------------------------- |
| `timeout`  |                                     |             | long                | Timeout, unit millions秒                                                           |
| `flowId`   |                                     |             | long                | The logo of this requestID                                                             |
| `instance` |                                     |             | map<string, object> |                                                                              |
|            | `namespace`                         |             | string              | Named empty service间                                                       |
|            | `service`                           |             | string              | Templated service name称                                                                 |
|            | `include_unhealthy_instances`       |             | string              | Set whether the service route contains unhealthy service instances.Optional, default is not included, string BOOL value: "true" |
|            | `include_circuit_breaker_instances` |             | string              | Set whether or not the service route contains a fuse service instance.Optional, default is not included, string BOOL value: "true" |
|            | `skip_route_filter`                 |             | string              | Set whether you skip the service route.Optional, default does not skip the service route, string BOOL value: "True" |
|            | `canary`                            |             | string              | Set which Titan service call例                                                   |
|            | `source_set_name`                   |             | string              | Set which set of calls务                                                      |
|            | `metadata_failover_type`            |             | string              | Set the downgrade policy when the metadata routing failed, the default is not degraded |
|            | `source_service`                    |             | map<string, string> | Set source service information for service routing calculations.Optional |
|            |                                     | `namespace` | string              | Source service name间                                                               |
|            |                                     | `service`   | string              | Source service名                                                                     |
|            |                                     | `metadata`  | map<string, string> | Source service instance label letter息                                                         |

*Function execution returns*

| First-class parameter name | Secondary parameter name  | Three-level parameter name          | Parameter Type            | Parameter                 |
| :----------- | :------------ | :-------------------- | :------------------ | :----------------------- |
| `code`       |               |                       | int                 | Method execution status code |
| `err_msg`    |               |                       | string              | Error message |
| `response`   |               |                       | map<string, object> | InstancesResponse |
|              | `flow_id`     |                       | long                | Request water |
|              | `service`     |                       | string              | Service Name |
|              | `namespace`   |                       | string              | Namespaces |
|              | `revision`    |                       | string              | Version Information |
|              | `metadata`    |                       | map<string, string> | Service metadata |
|              | `weight_type` |                       | string              | Weight type |
|              | `subset`      |                       | map<string, string> | Subset |
|              | `instances`   |                       | map<string, object> | Service instance list |
|              |               | `instance_id`         | string              | Service instance ID |
|              |               | `host`                | string              | Service node IP or domain name |
|              |               | `port`                | int                 | Node port number |
|              |               | `container_name`      | string              | Container name in instance metadata information |
|              |               | `internal_set_name`   | string              | SET name in instance metadata information |
|              |               | `logic_set`           | string              | Instance logicset information |
|              |               | `region`              | string              | location region |
|              |               | `zone`                | string              | location zone |
|              |               | `campus`              | string              | location campus |
|              |               | `vpc_id`              | string              | Get service instance VPC ID |
|              |               | `protocol`            | string              | Instance protocol information |
|              |               | `version`             | int                 | Instance version number information |
|              |               | `weight`              | int                 | Example static weight value, 0-1000 |
|              |               | `priority`            | int                 | Instance priority |
|              |               | `dynamic_weight`      | int                 | Instance dynamic weight |
|              |               | `hash_key`            | int                 | GetHash |
|              |               | `locality_aware_info` | int                 | locality_aware_info |
|              |               | `healthy`             | bool                | Instance health status |
|              |               | `isola`               | bool                | Instance isolation state |
|              |               | `metadata`            | map<string, string> | Example metadata information |

> Specific code use example

```php
$polaris_client = new PolarisClient(array());

// 初始化服务提供者的能力
$polaris_client->InitConsumer();

$init_service_info = array(
   "namespace" => "default",
    "service" => "php_ext_test",
    "canary" => "test_vpc",
    "source_service" => array(
        "namespace" => "",
        "service" => "",
        "metadata" => array(
            "env" => "pre"
        )
    )
);

$timeout = 500;
$flow_id = 123456;

$res = $polaris_client->GetInstances($init_service_info, $timeout, $flow_id);
var_dump($res);
```

### GetAllInstances

> Method use

Used to initialize service data in advance

> Parameter Description

*Request parameters*

| parameter name   |                                     |             | Parameter Type            | Parameter                                                                     |
| :--------- | :---------------------------------- | :---------- | :------------------ | :--------------------------------------------------------------------------- |
| `timeout`  |                                     |             | long                | Timeout, unit millions秒                                                           |
| `flowId`   |                                     |             | long                | The logo of this requestID                                                             |
| `instance` |                                     |             | map<string, object> |                                                                              |
|            | `namespace`                         |             | string              | Named empty service间                                                       |
|            | `service`                           |             | string              | Templated service name称                                                                 |
|            | `include_unhealthy_instances`       |             | string              | Set whether the service route contains unhealthy service instances.Optional, default is not included, string BOOL value: "true" |
|            | `include_circuit_breaker_instances` |             | string              | Set whether or not the service route contains a fuse service instance.Optional, default is not included, string BOOL value: "true" |
|            | `skip_route_filter`                 |             | string              | Set whether you skip the service route.Optional, default does not skip the service route, string BOOL value: "True" |
|            | `canary`                            |             | string              | Set which Titan service call例                                                   |
|            | `source_set_name`                   |             | string              | Set which set of calls务                                                      |
|            | `metadata_failover_type`            |             | string              | Set the downgrade policy when the metadata routing failed, the default is not degraded |
|            | `source_service`                    |             | map<string, string> | Set source service information for service routing calculations.Optional |
|            |                                     | `namespace` | string              | Source service name间                                                               |
|            |                                     | `service`   | string              | Source service名                                                                     |
|            |                                     | `metadata`  | map<string, string> | Source service instance label letter息                                                         |

*函数执行返回*

| First-class parameter name | Secondary parameter name  | Three-level parameter name          | Parameter Type            | Parameter                 |
| :----------- | :------------ | :-------------------- | :------------------ | :----------------------- |
| `code`       |               |                       | int                 | Method execution status code  |
| `err_msg`    |               |                       | string              | Error message  |
| `response`   |               |                       | map<string, object> | InstancesResponse  |
|              | `flow_id`     |                       | long                | Request water  |
|              | `service`     |                       | string              | Service Name  |
|              | `namespace`   |                       | string              | Namespaces  |
|              | `revision`    |                       | string              | Version Information  |
|              | `metadata`    |                       | map<string, string> | Service metadata  |
|              | `weight_type` |                       | string              | Weight type  |
|              | `subset`      |                       | map<string, string> | Subset  |
|              | `instances`   |                       | map<string, object> | Service instance list  |
|              |               | `instance_id`         | string              | Service instance ID  |
|              |               | `host`                | string              | Service node IP or domain name  |
|              |               | `port`                | int                 | Node port number  |
|              |               | `container_name`      | string              | Container in instance metadata information名 |
|              |               | `internal_set_name`   | string              | SET name in instance metadata information  |
|              |               | `logic_set`           | string              | Instance logicset information  |
|              |               | `region`              | string              | location region  |
|              |               | `zone`                | string              | location zone  |
|              |               | `campus`              | string              | location campus  |
|              |               | `vpc_id`              | string              | Get service instance VPC ID  |
|              |               | `protocol`            | string              | Instance protocol information  |
|              |               | `version`             | string              | Instance version number information  |
|              |               | `weight`              | int                 | Example static weight value, 0-1000  |
|              |               | `priority`            | int                 | Instance priority  |
|              |               | `dynamic_weight`      | int                 | Instance dynamic weight  |
|              |               | `hash_key`            | int                 | GetHash  |
|              |               | `locality_aware_info` | int                 | locality_aware_info  |
|              |               | `healthy`             | bool                | Instance health status  |
|              |               | `isola`               | bool                | Instance isolation state  |
|              |               | `metadata`            | map<string, string> | Example metadata information  |

> Specific code use example

```php
$polaris_client = new PolarisClient(array());

// 初始化服务提供者的能力
$polaris_client->InitConsumer();

$init_service_info = array(
    "namespace" => "default",
    "service" => "php_ext_test",
    "canary" => "test_vpc",
    "source_service" => array(
        "namespace" => "",
        "service" => "",
        "metadata" => array(
            "env" => "pre"
        )
    )
);

$timeout = 500;
$flow_id = 123456;

$res = $polaris_client->GetAllInstances($init_service_info, $timeout, $flow_id);
var_dump($res);
```

### UpdateServiceCallResult

> Method use

Used to initialize service data in advance

> Parameter Description

*Request parameters*

| First-class parameter name | Secondary parameter name          | Three-level parameter name | Parameter Type            | Parameter                                                                                        |
| :----------- | :-------------------- | :----------- | :------------------ | :---------------------------------------------------------------------------------------------- |
| `timeout`    |                       |              | long                | Timeout, unit millions秒                                                                            |
| `flowId`     |                       |              | long                | The logo of this requestID                                                                            |
| `instance`   |                       |              | map<string, object> |                                                                             |
|              | `namespace`           |              | string              | Named empty service间                                                                          |
|              | `service`             |              | string              | Templated service name称                                                                            |
|              | `instance_id`         |              | string              | Service instanceID                                                                            |
|              | `host`                |              | string              | Service instance host (optional, if the service instance ID is set, this is not set, prioritize the service instanceID)                    |
|              | `port`                |              | string              | Service instance port (optional, if the service instance ID is set, this can not be set, prioritize the service instance ID), string number: "200" |
|              | `delay`               |              | string              | Setting up service instance calls delay, string numbers:"200"                                                         |
|              | `locality_aware_info` |              | string              | Set the information that needs to be passed, the string number:"200"                                            |
|              | `ignore_half_open`    |              | string              | Set whether to skip the semi-open detection node, "True" OR"false"                                                 |
|              | `ret_status`          |              | string              | Call Back Status, Error, Timeout,ok                                                                |
|              | `ret_code`            |              | string              | Set the call return code.Optional, used to support your own insertion according to the return code件                                          |
|              | `subset`              |              | map<string, string> | Set up the tone service Subset letter息                                                                          |
|              | `labels`              |              | map<string, string> | Set up tone service labels letter息                                                                          |
|              | `source_service`      |              | map<string, string> | Set source service letter息                                                                            |
|              |                       | `namespace`  | string              | Source service name间                                                                            |
|              |                       | `service`    | string              | Source service名                                                                            |
|              |                       | `metadata`   | map<string, string> | Source service instance label letter息                                                                            |

*Function execution returns*

| First-class parameter name | Parameter Type | Parameter       |
| :----------- | :------- | :------------- |
| `code`       | int      | Method execution status code |
| `err_msg`    | string   | Error message |

> Specific code use example

```php
$polaris_client = new PolarisClient(array());

// 初始化服务提供者的能力
$polaris_client->InitConsumer();

$init_service_info = array(
    "namespace" => "default",
    "service" => "php_ext_test",
    "vpc_id" => "test_vpc",
    "locality_aware_info" => "",
    "ret_status" => "ok",
    "labels" => array(
        "user_id" => "uin_001"
    ),
    "source_service" => array(
        "namespace" => "",
        "service" => "",
        "metadata" => array(
            "env" => "pre"
        )
    )
);

$timeout = 500;
$flow_id = 123456;

$res = $polaris_client->UpdateServiceCallResult($init_service_info, $timeout, $flow_id);
var_dump($res);
```

## LimitAPI

### GetQuota

> Method use

Obtain quota

> Parameter Description

*Request parameters*

| First-class parameter name | Parameter Type            | Parameter                                                  |
| :----------- | :------------------ | :-------------------------------------------------------- |
| `subset`     | map<string, string> | Set the service subset of the requested request, optional |
| `labels`     | map<string, string> | Setting tags for selecting a current limiting configuration |
| `amount`     | string              | Set the quantity of the quota required to be assigned, optional, default is 1, string number: 100 |
| `namespace`  | string              | Namespace where the service is located |
| `service`    | string              | Templated service name |

*函数执行返回*

| First-class parameter name   | Secondary parameter name        | Parameter Type            | Parameter                                                   |
| :------------- | :------------------ | :------------------ | :--------------------------------------------------------- |
| `code`         |                     | int                 | Method execution status code |
| `err_msg`      |                     | string              | Error message |
| `quota_result` |                     | map<string, object> | All keys configured in the rules |
|                | `wait_time`         | long                | How long does it take to get quotas? |
|                | `degrade`           | bool                | Whether it is downgraded |
|                | `duration`          | long                | Configuration cycle |
|                | `quota_left`        | long                | Remainder |
|                | `quota_all`         | long                | Configure quota |
|                | `quota_result_code` | long                | Quota acquisition result (0: quota is normal, 1: quota is limited, 2: demand needs to wait retry) |

> Specific code use example

```php
$polaris_client = new PolarisClient(array());

// 初始化服务提供者的能力
$polaris_client->InitLimit();

$quota_request = array(
    "namespace" => "default",
    "service" => "php_ext_test",
    "amount" => "",
    "subset" => array(
        "{key}" => "{value}"
    ),
    "labels" => array(
        "{key}" => "{value}"
    )
);

$res = $polaris_client->GetQuota($quota_request);
var_dump($res);

/*
arra(
    "code" =>  ,
    "err_msg" => ,
    "quota_result" => array(
        "wait_time" => 10,
        "degrade" => true,
        "duration" => ,
        "quota_left" => 5,
        "quota_all" => 10,
        "quota_result_code" => 0
    )
)
 */
```

### UpdateCallResult

> Method use

Update request quota call results

> Parameter Description

*Request parameters*

| First-class parameter name    | Parameter Type            | Parameter                         |
| :-------------- | :------------------ | :------------------------------- |
| `namespace`     | long                | Namespaces |
| `service`       | long                | service name |
| `response_time` | string              | Request response time, string number: "1000" |
| `respont_type`  | string              | "Limit"、"Failed"、"OK" |
| `respont_code`  | long                | Id identification ID of this request |
| `labels`        | map<string, string> |                                  |
| `subset`        | map<string, string> |                                  |

*Function execution returns*

| First-class parameter name | Parameter Type | Parameter       |
| :----------- | :------- | :------------- |
| `code`       | int      | Method execution status code|
| `err_msg`    | string   | Error message|

> Specific code use example

```php
$polaris_client = new PolarisClient(array());

// 初始化服务提供者的能力
$polaris_client->InitConsumer();

$call_result = array(
    "namespace" => "default",
    "service" => "php_ext_test",
    "response_time" => "100",
    "response_code" => "100",
    "response_type" => "100",
    "labels" => array(),
    "subset" => array(),
);

$res = $polaris_client->UpdateCallResult($call_result);
var_dump($res);
```

### InitQuotaWindow

> Method use

Initialization quota window, optional, used to initialize the window to reduce the first quota delay

> Parameter Description

*Request parameters*

| First-class parameter name | Parameter Type            | Parameter                                              |
| :----------- | :------------------ | :---------------------------------------------------- |
| `subset`     | map<string, string> | Set the service subset of the requested request, optional |
| `labels`     | map<string, string> | Setting tags for selecting a current limiting configuration |
| `amount`     | string              | Set the number of quotas that requests need to be assigned, optional, default is 1, string number |
| `namespace`  | string              | Namespace where the service is located |
| `service`    | string              | Templated service name |

*Function execution returns*

| First-class parameter name | Parameter Type | Parameter       |
| :----------- | :------- | :------------- |
| `code`       | int      | Method execution status code |
| `err_msg`    | string   | Error message |

> Specific code use example

```php
$polaris_client = new PolarisClient(array());

// 初始化服务提供者的能力
$polaris_client->InitLimit();

$quota_request = array(
    "namespace" => "default",
    "service" => "php_ext_test",
    "amount" => "",
    "subset" => array(
        "{key}" => "{value}"
    ),
    "labels" => array(
        "{key}" => "{value}"
    )
);

$res = $polaris_client->InitQuotaWindow($quota_request);
var_dump($res);
```
